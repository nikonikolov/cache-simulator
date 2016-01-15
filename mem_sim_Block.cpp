#include "mem_sim_Block.h"

/*
Block::Block(const int& nWordsIn, const int& nBytesIn){
	nWords = nWordsIn;
	nBytes = nBytesIn;

	ptr = new Word*[nWords];
	for(int i=0; i<nWords; i++){
		ptr[i] = new Word(nBytes);
	}
}

Block::~Block(){
	for(int i=0; i<nWords; i++){
		delete ptr[i];
	}

	delete [] ptr;
}
*/


Block::Block(const uint32_t& nWordsIn, const uint32_t& nBytesIn) :
	nWords(nWordsIn), nBytes(nBytesIn), words(nWordsIn, Word(nBytesIn)), valid(false), dirty(false), tag(0) {
	
	/*for(int i=0; i<nWords; i++){
		words.push_back(Word(nBytes));
	}*/
}

Block::Block(const Block& BlockIn) :
	nWords(BlockIn.nWords), nBytes(BlockIn.nBytes), valid(BlockIn.valid), dirty(BlockIn.dirty), tag(BlockIn.tag){

	for(int i=0; i<nWords; i++){
		words.push_back(BlockIn[i]);
	}	
}


Block::~Block(){
}


const Word& Block::operator[](uint32_t idx) const{
	return words[idx];
}

Word& Block::operator[](uint32_t idx){
	return words[idx];
}


uint32_t Block::get_tag() const{
	return tag;
}
bool Block::get_valid() const{
	return valid;
}

bool Block::get_dirty() const{
	return dirty;
}

Word Block::readWord(const uint32_t& idx) const{
	return words[idx];
}

void Block::writeWord(const uint32_t& idx, const Word& WordIn){
	if(!valid) return;
	
	words[idx] = WordIn;
	dirty = true;
}

void Block::writeBack(Memory& mem){
	if(!valid) return;

	for(int i=0; i<nWords; i++){
		mem.writeWord(tag*nWords+i, words[i]);
	}
	dirty = false;
}	

void Block::fetchBlock(const uint32_t& block_address, Memory& mem){
	for(int i=0; i<nWords; i++){
		words[i] = mem.readWord(block_address*nWords+i);
	}

	dirty = false;
	valid = true;
	tag = block_address;
}

ostream& operator<<(ostream& out, const Block& BlockIn){
	out<<"tag: "<<BlockIn.tag<<"\t"<<"valid: "<<BlockIn.valid<<"\t"<<"dirty: "<<BlockIn.dirty<<endl;
	for(int i=0; i<BlockIn.words.size(); i++){
		out<<"\t"<<BlockIn.words[i];
	}
	return out;
}

