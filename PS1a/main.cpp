#include <iostream>
#include <string>
#include "FibLFSR.h"

int main(){
	FibLFSR fib("1011011000110110");

	// std::cout<<fib<<std::endl;
	// for(int i=0; i<10; i++){
	// 	int step=fib.step();
	// 	std::cout<<fib<<" "<<step<<std::endl;
	// }
	
	for(int j=5; j<12; j++){
		int value=fib.generate(5);
		std::cout<<fib<<" "<<value<<std::endl;
	}
	return 0;
}