#ifndef MEM_SIM_Block_H
#define MEM_SIM_Block_H

#include "mem_sim_Word.h"
#include "mem_sim_Memory.h"


class Block{

public:
	Block(const uint32_t& nWordsIn, const uint32_t& nBytesIn);
	Block(const Block& BlockIn);
	~Block();

	uint32_t get_tag() const;
	bool get_valid() const;
	bool get_dirty() const;

	Word readWord(const uint32_t& idx) const;

	void writeBack(Memory& mem);
	void fetchBlock(const uint32_t& block_address, Memory& mem);


	const Word& operator[](uint32_t idx) const;
	Word& operator[](uint32_t idx);


private:
	//Word ** ptr;
	vector<Word> words;

	bool valid;
	bool dirty;
	uint32_t tag;

	uint32_t nWords;
	uint32_t nBytes;
};


#endif


