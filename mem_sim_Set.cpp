#include "mem_sim_Set.h"

/*
Set::Set(const int& nBlocksIn, const int& nWordsIn, const int& nBytesIn) :
	nBlocks(nBlocksIn), nWords(nWordsIn), nBytes(nBytesIn) {

	ptr = new Block*[nBlocks];
	for(int i=0; i<nBlocks; i++){
		ptr[i] = new Block(nWords, nBytes);
	}
}

Set::~Set(){
	for(int i=0; i<nBlocks; i++){
		delete ptr[i];
	}

	delete [] ptr;
}
*/

Set::Set(const uint32_t& nBlocksIn, const uint32_t& nWordsIn, const uint32_t& nBytesIn) :
	nBlocks(nBlocksIn), nWords(nWordsIn), nBytes(nBytesIn), blocks(nBlocksIn, Block(nWordsIn, nBytesIn)) {

		for(uint32_t i=0; i<nBlocks; i++){
			MRU_list.push_back(i);
		}
}

Set::Set(const Set& SetIn) :
	nBlocks(SetIn.nBlocks), nWords(SetIn.nWords), nBytes(SetIn.nBytes){
	
	for(int i=0; i<nBlocks; i++){
		blocks.push_back(SetIn[i]);
	}	


}

Set::~Set(){
}

const Block& Set::operator[](uint32_t idx) const{
	return blocks[idx];
}

Block& Set::operator[](uint32_t idx){
	return blocks[idx];
}

Word Set::readWord(const uint32_t& word_address, Memory& mem, uint32_t& access_time, int& HitMiss){
	HitMiss = HIT;

	uint32_t block_address = word_address/nWords;
	uint32_t block_offset = word_address%nWords;

	for(int i=0; i<nBlocks; i++){
		if( (blocks[i].get_tag() == block_address) && blocks[i].get_valid() ){
			updateLRU(i);		// Update the LRU list
			return blocks[i].readWord(block_offset);
		}
	}

	// Function did not return => MISS
	HitMiss = MISS;

	// find the index of LRU block 
	uint32_t LRU_block = findLRU();

	// write back Block if dirty
	if(blocks[LRU_block].get_dirty()){
		// include writeBlock time 
		access_time += mem.get_writeTime();
		blocks[LRU_block].writeBack(mem);
	}

	// replace Block
	blocks[LRU_block].fetchBlock(block_address, mem);

	updateLRU(LRU_block);		// Update the LRU list

	// include readBlock time
	access_time += mem.get_readTime();

	// return data
	return blocks[LRU_block].readWord(block_offset);
}


void Set::writeWord(const uint32_t& word_address, const Word& data, Memory& mem, uint32_t& access_time, int& HitMiss){
	HitMiss = HIT;

	uint32_t block_address = word_address/nWords;
	uint32_t block_offset = word_address%nWords;

	for(int i=0; i<nBlocks; i++){
		if( (blocks[i].get_tag() == block_address) && blocks[i].get_valid() ){
			updateLRU(i);		// Update the LRU list
			blocks[i].writeWord(block_offset);
			return;
		}
	}

	// Function did not return => MISS
	HitMiss = MISS;

	// find the index of LRU block 
	uint32_t LRU_block = findLRU();

	// write back Block if dirty
	if(blocks[LRU_block].get_dirty()){
		// include writeBlock time 
		access_time += mem.get_writeTime();
		blocks[LRU_block].writeBack(mem);
	}

	// replace Block
	blocks[LRU_block].fetchBlock(block_address, mem);

	updateLRU(LRU_block);		// Update the LRU list

	// include readBlock time
	access_time += mem.get_readTime();

	// write data
	blocks[LRU_block].writeWord(block_offset, data);
}


void Set::updateLRU(const uint32_t& idx){
	list<uint32_t>::iterator it;
	
	for(it=MRU.begin(); it!=MRU.end(); ++it){
		if(idx== *it){
			list<uint32_t>::iterator it_head = MRU.begin();
			uint32_t tmp = *it_head;
			*it_head = *it;
			*it = tmp;
		}
	}
}

uint32_t Set::findLRU(){
	return MRU_list.back();
}

