#include "mem_sim_methods.h"

void parse_inputs(int argc, char* argv[], vector<int>& args){
	if(argc != 9) throw string("Invalid number of input arguments");

	for(int i=1; i<argc; i++){
		args.push_back(atoi(argv[i]));
	}
}


Word parse_word(const string& str_word, vector<uint8_t>& data){

	//cout<<str_word<<endl;

	for(int i=0; i<str_word.size(); i+=2){
    	string tmp_str = str_word.substr(i,2);

    	uint8_t result = (uint8_t)strtoul(tmp_str.c_str(), NULL, 16);

    	data.push_back(result);
    	//cout<<tmp_str<<endl;
    	/*
    	uint32_t result;
    	int64_t tmpresult;
    	string tmp_str = str_word.substr(i,2);
		
		stringstream ss;
    	ss<<hex<<tmp_str;
    	ss >> tmpresult;
    	result = (uint32_t)tmpresult;
		cout<<setfill('0')<< setw(2)<<hex<<uppercase<<result;
    	data.push_back((uint8_t)result);
    	*/

    	//cout<<hex<<result<<endl;
		//cout<<setfill('0')<< setw(2)<<hex<<uppercase<<(uint32_t)data[i/2];
	}

	return Word(data);
}

