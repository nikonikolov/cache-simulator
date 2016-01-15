#include "mem_sim_RetObj.h"

RetObj::RetObj(const int& setIdxIn, const int& HitMissIn, const int& TimeIn, const Word& WordIn) :
	setIdx(setIdxIn), HitMiss(HitMissIn), Time(TimeIn)/*, data(WordIn)*/ {
	
	WordPtr = new Word(WordIn);
}

RetObj::RetObj(const int& setIdxIn, const int& HitMissIn, const int& TimeIn) :
	setIdx(setIdxIn), HitMiss(HitMissIn), Time(TimeIn), WordPtr(NULL)/*data(0)*/ {}

RetObj::~RetObj(){
	if(WordPtr !=NULL) delete WordPtr;
}


ostream& operator<<(ostream& out, const RetObj& obj){
	out<<obj.setIdx<<" ";
	if(obj.HitMiss == HIT) out<<"hit ";
	else out<<"miss ";

	out<<obj.Time;
	//if(obj.data.get_size() != 0) out<<" "<<obj.data;
	if(obj.WordPtr != NULL) out<<" "<<(*(obj.WordPtr));
	return out;
}
