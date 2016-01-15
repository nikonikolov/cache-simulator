#include "mem_sim_Cache.h"

/*
Cache::Cache(const int& nSetsIn, const int& nBlocksIn, const int& nWordsIn, const int& nBytesIn){
	nSets = nSetsIn;
	nBlocks = nBlocksIn;
	nWords = nWordsIn;
	nBytes = nBytesIn;
	
	ptr = new Set*[nSets];
	for(int i=0; i<nSets; i++){
		ptr[i] = new Set(nBlocks, nWords, nBytes);
	}
}

Cache::~Cache(){
	for(int i=0; i<nSets; i++){
		delete ptr[i];
	}
	
	delete [] ptr;
}
*/

Cache::Cache(const int& nSetsIn, const int& nBlocksIn, const int& nWordsIn, const int& nBytesIn, const int& hitTimeIn):
	nSets(nSetsIn), nBlocks(nBlocksIn), nWords(nWordsIn), nBytes(nBytesIn), hitTime(hitTimeIn), 
	sets(nSetsIn, Set(nBlocksIn, nWordsIn, nBytesIn)){	

	/*for(int i=0; i<nSets; i++){
		sets.push_back(Set(nBlocks, nWords, nBytes));
	}*/
}

Cache::~Cache(){
}


const Set& Cache::operator[](int idx) const{
	return sets[idx];
}

Set& Cache::operator[](int idx){
	return sets[idx];
}


RetObj Cache::readWord(const uint32_t& byte_address, Memory& mem){
	
	int HitMiss;
	// The first nWords(words per block) map to the first set, the second batch to the second set and so on
	// That goes on until you reach the first nWords*nSets when the first column of blocks in the cache is already full
	// Then the nWords*nSets word maps again to the first set
	// Repeating that nBlocks times the cache gets filled
	// Then after nBlocks*nWords*nSets word addresses again start mapping to the first set

	uint32_t word_address = byte_address/nBytes;
	uint32_t setIdx = (word_address/nWords) %nSets;

	// include HitTime
	uint32_t execution_time = hitTime; 
	//cout<<setIdx<<" "<<nSets<<endl;
	
	// Read Word
	Word data = sets[setIdx].readWord(word_address, mem, execution_time, HitMiss);
	return RetObj(setIdx, HitMiss, execution_time, data);
	//return RetObj(setIdx, HitMiss, execution_time, sets[setIdx].readWord(word_address, mem, execution_time, HitMiss));
}


RetObj Cache::writeWord(const uint32_t& byte_address, const Word& data, Memory& mem){
	int HitMiss;

	uint32_t word_address = byte_address/nBytes;
	uint32_t setIdx = (word_address/nWords) %nSets;

	// include HitTime
	uint32_t execution_time = hitTime; 
	
	// write Word
	sets[setIdx].writeWord(word_address, data, mem, execution_time, HitMiss);

	return RetObj(setIdx, HitMiss, execution_time);
}

int Cache::flush(Memory& mem){
	int execution_time=0;

	for(int i=0; i<sets.size(); i++){
		execution_time += sets[i].flush(mem);
	}

	return execution_time;
}


void Cache::debug(){
	cout<<"debug-ack-begin"<<endl;
	for(int i=0; i<sets.size(); i++){
		cout<<"Set "<<i<<endl;
		cout<<sets[i]<<endl<<endl;
	}
	cout<<"debug-ack-end"<<endl;
}

