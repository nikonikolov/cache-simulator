#include <iostream>
#include <string>

#include "mem_sim_methods.h"
#include "mem_sim_Memory.h"
#include "mem_sim_Cache.h"

#define ADDRESS_BITS 		1
#define BYTES_PER_WORD 		2
#define WORDS_PER_BLOCK 	3
#define BLOCKS_PER_SET 		4
#define SETS_PER_CACHE 		5
#define HIT_TIME 			6
#define READ_TIME 			7	
#define WRITE_TIME 			8	

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

	Cache cacheMem(args[SETS_PER_CACHE], args[BLOCKS_PER_SET], args[WORDS_PER_BLOCK], args[BYTES_PER_WORD]);
	Memory Mem(args[ADDRESS_BITS], args[BYTES_PER_WORD]);

	return 0;
}


