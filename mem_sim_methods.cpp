#include "mem_sim_methods.h"

void parse_inputs(int argc, char* argv[], vector<int>& args){
	if(argc != 9) throw "Invalid number of input arguments";

	for(int i=1; i<argc; i++){
		args.push_back(atoi(argv[i]));
	}
}

