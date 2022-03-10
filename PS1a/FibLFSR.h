#ifndef FIBLFSR_H
#define FIBLFSR_H
#include <iostream>
#include <string>


class FibLFSR {
public:
	FibLFSR(std::string newSeed); // constructor to create LFSR with
								// the given initial seed and tap
	int step(); // simulate one step and return the
				// new bit as 0 or 1
	int generate(int k); // simulate k steps and return
						// k-bit integer
	int getSize(void);	//size of string seed 

	friend std::ostream &operator<<(std::ostream &out, const FibLFSR& obj);

private: 
	std::string seed;
};
			
#endif 