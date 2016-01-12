#include "mem_sim_Word.h"

/*
Word::Word(const int& nBytesIn){
	nBytes = nBytesIn;
	ptr = new uint8_t[nBytes]();
}

Word::~Word(){
	delete [] ptr;
}
*/


Word::Word(const int& nBytesIn) :
	nBytes(nBytesIn), bytes(nBytesIn, 0) {
	/*for(int i=0; i<nBytes; i++){
		bytes.push_back(0);
	}*/
}


Word::Word(const Word& WordIn) :
	nBytes(WordIn.nBytes){

	for(int i=0; i<nBytes; i++){
		bytes.push_back(WordIn[i]);
	}	
}


Word::~Word(){
}

void Word::operator=(const Word& WordIn){
	if(this != &WordIn){
		
		if(nBytes != WordIn.nBytes) throw "Invalid Assignment: Words with different lengths cannot be assigned";
		
		bytes.clear();
		for(int i=0; i<nBytes; i++){
			bytes.push_back(WordIn[i]);
		}
	}
}

const uint8_t& Word::operator[](int idx) const{
	return bytes[idx];
}

uint8_t& Word::operator[](int idx){
	return bytes[idx];
}

ostream& operator<<(ostream& out, const Word& WordIn){
	for(int i=0; i<nBytes; i++){
		out<<setfill('0')<< setw(2)<<hex<<uppercase<<(unsigned)WordIn[i];
	}

	return out;
}

