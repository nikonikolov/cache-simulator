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

Word::Word(const vector<uint8_t>& data_in) :
	nBytes(data_in.size()){

	for(int i=0; i<data_in.size(); i++){
		bytes.push_back(data_in[i]);
	}	

	//cout<<*this<<" nBytes:"<<nBytes<<endl;
}

Word::~Word(){
}

void Word::operator=(const Word& WordIn){
	if(this != &WordIn){
		
		if(nBytes != WordIn.nBytes){
			//cout<<"nBytes: "<<nBytes<<" WordIn.nBytes: "<<WordIn.nBytes<<endl;
			throw "Invalid Assignment: Words with different lengths cannot be assigned";
		} 
		//cout<<"done"<<endl;
		
		bytes.clear();
		for(int i=0; i<nBytes; i++){
			bytes.push_back(WordIn[i]);
		}
	}
}


int Word::get_size() const{
	return nBytes;
}

const uint8_t& Word::operator[](int idx) const{
	return bytes[idx];
}

uint8_t& Word::operator[](int idx){
	return bytes[idx];
}

ostream& operator<<(ostream& out, const Word& WordIn){
	for(int i=0; i<WordIn.nBytes; i++){
		out<<setfill('0')<< setw(2)<<hex<<uppercase<<(uint32_t)WordIn[i];
	}

	return out;
}

