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


	/*Functions to write:
		LRU replacement
		Write back to cache on flush or replacement - private
		
		Debug response: "debug-ack-begin"\n\n"debug-ack-end" - without the quotes
		Debug - e.g. print current state of cache - good one, not obligatory but good for debugging
		
		NOTE THAT Data is a string of hex digits with upper-case letters, which must be of the same width as a cache word 
		(i.e. two hex digits per byte). The ordering is from highest address to lowest. 
		
		Flush function: "flush-ack" time - ensure memory consistent with cache - does not include hit time,
		only the time needed to write dirty pages to mem
	*/

private:
	//Set ** ptr;
	vector<Set> sets;

	// if static this will mean that potentially two Caches of different size cannot be initialized
	int nSets;
	int nBlocks;
	int nWords;
	int nBytes;

	int hitTime;			// in cycles per access
};


#endif


