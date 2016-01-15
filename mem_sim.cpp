#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "mem_sim_methods.h"
#include "mem_sim_Memory.h"
#include "mem_sim_Cache.h"
#include "mem_sim_RetObj.h"

#define ADDRESS_BITS 		0
#define BYTES_PER_WORD 		1
#define WORDS_PER_BLOCK 	2
#define BLOCKS_PER_SET 		3
#define SETS_PER_CACHE 		4
#define HIT_TIME 			5
#define READ_TIME 			6	
#define WRITE_TIME 			7	

using namespace std;



int main(int argc, char *argv[]){
	vector<int> args;

	try{
		parse_inputs(argc, argv, args);
	}
	catch(string e){
		cout<<e<<endl;
		exit(EXIT_FAILURE);
	}
	//cout<<"completed"<<endl;
	/*for(int i=0; i<args.size(); i++){
		cout<<args[i]<<endl;
	}*/

	Cache cacheMem(args[SETS_PER_CACHE], args[BLOCKS_PER_SET], args[WORDS_PER_BLOCK], args[BYTES_PER_WORD], args[HIT_TIME]);
	Memory Mem(args[ADDRESS_BITS], args[BYTES_PER_WORD], args[READ_TIME], args[WRITE_TIME]);

	string line;
	while(getline(cin,line)){
		stringstream instream(line);
		string insarg;
		vector<string> params;
		
		insarg = line.substr(0,1);
		if(insarg=="#") continue;

		while( getline(instream, insarg, ' ') ){
			params.push_back(insarg);
		}

		if(params[0]=="read-req"){
			//cout<<"read"<<endl;
			RetObj TmpObj = cacheMem.readWord(atoi(params[1].c_str()),Mem);
			cout<<"read-ack "<<TmpObj<<endl;
		}
		if(params[0]=="write-req"){
			//cout<<"write"<<endl;
			vector<uint8_t> data;
			RetObj TmpObj = cacheMem.writeWord(atoi(params[1].c_str()), parse_word(params[2], data), Mem);
			cout<<"write-ack "<<TmpObj<<endl;
		}
		if(params[0]=="flush-req"){
			//cout<<"flush"<<endl;
			int TmpTime = cacheMem.flush(Mem);
			cout<<"flush-ack "<<TmpTime<<endl;
		}
		if(params[0]=="debug-req"){
			//cout<<"debug"<<endl;
			cacheMem.debug();
		}
	}

	return 0;
}


