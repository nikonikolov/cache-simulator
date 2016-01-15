#ifndef MEM_SIM_METHODS_H
#define MEM_SIM_METHODS_H

#include <cstdlib>
#include <string>
#include <vector>
#include <cstdint>
#include "mem_sim_Word.h"
#include <sstream>
#include <iomanip>

using namespace std;

void parse_inputs(int argc, char* argv[], vector<int>& args);
Word parse_word(const string& str_word, vector<uint8_t>& data);


#endif


