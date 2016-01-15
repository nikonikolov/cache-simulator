#ifndef MEM_SIM_Set_H
#define MEM_SIM_Set_H

#include "mem_sim_Block.h"

#include <list>
#include <iostream>

#define HIT 	1
#define MISS 	0

class Set{

public:
	Set(const uint32_t& nBlocksIn, const uint32_t& nWordsIn, const uint32_t& nBytesIn);
	Set(const Set& SetIn);
	~Set();

	const Block& operator[](uint32_t idx) const;
	Block& operator[](uint32_t idx);

	Word readWord(const uint32_t& word_address, Memory& mem, uint32_t& execution_time, int& HitMiss);
	void writeWord(const uint32_t& word_address, const Word& data, Memory& mem, uint32_t& execution_time, int& HitMiss);
	int flush(Memory& mem);

	friend ostream& operator<<(ostream& out, const Set& SetIn);

private:
	
	void updateLRU(const uint32_t& idx);
	uint32_t findLRU();

	//Block ** ptr;
	vector<Block> blocks;

	list<uint32_t> MRU_list;			// LRU block stays on bottom

	uint32_t nBlocks;
	uint32_t nWords;
	uint32_t nBytes;
};


#endif


