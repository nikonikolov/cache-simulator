#include "mem_sim_RetObj.h"

RetObj::RetObj(const int& setIdxIn, const int& HitMissIn, const int& TimeIn, const Word& WordIn) :
	setIdx(setIdxIn), HitMiss(HitMissIn), Time(TimeIn){
	
	WordPtr = new Word(WordIn);
}

RetObj::RetObj(const int& setIdxIn, const int& HitMissIn, const int& TimeIn) :
	setIdx(setIdxIn), HitMiss(HitMissIn), Time(TimeIn){}

RetObj::~RetObj(){
	if(WordPtr !=NULL) delete WordPtr;
}


ostream& operator<<(ostream& out, const RetObj& obj){
	out<<obj.setIdx<<" ";
	if(obj.HitMiss == HIT) out<<"Hit ";
	else out<<"Miss ";

	out<<obj.Time;
	if(WordPtr != NULL) out<<" "<<*obj.WordPtr;
	return out;
}
