#ifndef MEM_SIM_Memory_H
#define MEM_SIM_Memory_H

#include <cmath>


#include "mem_sim_Word.h"

class Memory{

public:
	Memory(const int& addressBitsIn, const int& bytesPerWordIn);
	~Memory();

	uint32_t get_readTime() const;
	uint32_t get_writeTime() const;
	
	Word readWord(const uint32_t& word_address);
	void writeWord(const uint32_t& word_address, const Word& wordIn);

	const Word& operator[](int idx) const;
	Word& operator[](int idx);

	/*Fucntions to implement
		2. get memory size - create one for bytes and one for words 
	*/

private:
	//Word ** ptr;
	vector<Word> words;
	uint32_t size;				// in bytes
	int nWords;
	int bytesPerWord;	

	int readTime;				// in cycles/Block
	int writeTime;				// in cycles/Block
};


#endif


