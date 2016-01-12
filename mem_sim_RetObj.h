#ifndef MEM_SIM_RetObj_H
#define MEM_SIM_RetObj_H

#include <cstdint>
#include <iostream>
#include <sting>

#include "mem_sim_Word.h"
#include "mem_sim_Set.h"

using namespace std;

class RetObj{

public:
	RetObj(const int& setIdxIn, const int& HitMissIn, const int& TimeIn, const Word& WordIn);
	RetObj(const int& setIdxIn, const int& HitMissIn, const int& TimeIn);
	~RetObj();

	friend ostream& operator<<(ostream& out, const RetObj& obj);

private:
	int setIdx;
	int HitMiss;
	int Time;
	Word* WordPtr = NULL;
};


#endif


