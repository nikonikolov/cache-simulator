#ifndef MEM_SIM_WORD_H
#define MEM_SIM_WORD_H

#include <iostream>
#include <iomanip>
#include <cstdint>
#include <vector>

using namespace std;

class Word{

public:
	Word(const int& nBytesIn);
	Word(const Word& WordIn);
	~Word();

	const uint8_t& operator[](int idx) const;
	uint8_t& operator[](int idx);
	void operator=(const Word& WordIn);
	friend ostream& operator<<(ostream& out, const Word& WordIn);

private:
	//uint8_t * ptr;
	vector<uint8_t> bytes;

	int nBytes;
};


#endif


