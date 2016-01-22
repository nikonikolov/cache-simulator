#ifndef MEM_SIM_Cache_H
#define MEM_SIM_Cache_H

#include "mem_sim_Set.h"
#include "mem_sim_RetObj.h"

class Cache{

public:
	Cache(const int& nSetsIn, const int& nBlocksIn, const int& nWordsIn, const int& nBytesIn, const int& hitTimeIn);
	~Cache();

	const Set& operator[](int idx) const;
	Set& operator[](int idx);

	RetObj readWord(const uint32_t& address, Memory& mem);
	RetObj writeWord(const uint32_t& byte_address, const Word& data, Memory& mem);
	int flush(Memory& mem);
	void debug();

private:
	uint32_t decode_address(const uint32_t& byte_address, uint32_t& word_address);

	vector<Set> sets;

	int nSets;
	int nBlocks;
	int nWords;
	int nBytes;

	int hitTime;			// in cycles per access
};


#endif


