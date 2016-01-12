#ifndef MEM_SIM_Set_H
#define MEM_SIM_Set_H

#include "mem_sim_Block.h"
#include "mem_sim_Memory.h"

#include <list>

#define HIT 	1
#define MISS 	0

class Set{

public:
	Set(const uint32_t& nBlocksIn, const uint32_t& nWordsIn, const uint32_t& nBytesIn);
	Set(const Set& SetIn);
	~Set();

	const Block& operator[](uint32_t idx) const;
	Block& operator[](uint32_t idx);

	Word readWord(const uint32_t& word_address, Memory& mem, uint32_t& access_time, int& HitMiss);

private:
	
	void updateLRU(const uint32_t& idx);
	uint32_t findLRU();

	//Block ** ptr;
	vector<Block> blocks;

	list<uint32_t> MRU_list;			// LRU block stays on botoom

	uint32_t nBlocks;
	uint32_t nWords;
	uint32_t nBytes;
};


#endif


