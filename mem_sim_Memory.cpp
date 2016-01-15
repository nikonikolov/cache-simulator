#include "mem_sim_Memory.h"

/*
Memory::Memory(const int& addressBitsIn, const int& bytesPerWordIn){
	size = pow(2, addressBitsIn);
	bytesPerWord = bytesPerWordIn;
	nWords = size/bytesPerWord;

	ptr = new Word*[nWords];
	for(int i=0; i<nWords; i++){
		ptr[i] = new Word(bytesPerWord);
	}
}

Memory::~Memory(){
	for(int i=0; i<nWords; i++){
		delete ptr[i];
	}

	delete [] ptr;
}

Word Memory::readWord(const uint32_t& address){
	return *(ptr[address/bytesPerWord]); 
}
*/

Memory::Memory(const int& addressBitsIn, const int& bytesPerWordIn, const int& readTimeIn, const int& writeTimeIn) :
	size(pow(2, addressBitsIn)), bytesPerWord(bytesPerWordIn), readTime(readTimeIn), writeTime(writeTimeIn) {
	
	nWords = size/bytesPerWord;

	//words (nWords, Word(bytesPerWordIn))
	/*size = pow(2, addressBitsIn);
	bytesPerWord = bytesPerWordIn;
	nWords = size/bytesPerWord;
	
	ptr = new Word*[nWords];
	for(int i=0; i<nWords; i++){
		ptr[i] = new Word(bytesPerWord);
	}
	*/
	for(int i=0; i<nWords; i++){
		words.push_back(Word(bytesPerWord));
	}
}

Memory::~Memory(){
}


const Word& Memory::operator[](int idx) const{
	return words[idx];
}

Word& Memory::operator[](int idx){
	return words[idx];
}

uint32_t Memory::get_writeTime() const{
	return writeTime;
}

uint32_t Memory::get_readTime() const{
	return readTime;
}


Word Memory::readWord(const uint32_t& word_address){
	return words[word_address]; 
}
	
void Memory::writeWord(const uint32_t& word_address, const Word& WordIn){
	words[word_address] = WordIn;
}

