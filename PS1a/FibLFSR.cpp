#include <iostream>
#include <string>
#include "FibLFSR.h"


FibLFSR::FibLFSR(std::string newSeed):seed(newSeed){}

int FibLFSR::step(){
	std::string stringBit;
	int size = seed.size();
	int leftMostBit = seed[0];
	int bitPos13 = seed[2];
	int bitPos12 = seed[3];
	int bitPos10 = seed[5];
	int bit = ((leftMostBit^bitPos13)^bitPos12)^bitPos10;
	seed = seed.substr(1, size - 1);
	stringBit = std::to_string(bit);
	seed += stringBit;
	return bit;
}

int FibLFSR::generate(int k){
	int a=0;
	for(int i=0;i<k;i++){
		a=a<<1|step();
	}
	return a;
}
int FibLFSR::getSize(void){
	return seed.size();
}


std::ostream &operator<<(std::ostream &out, const FibLFSR& obj){
	return out<<obj.seed;
}