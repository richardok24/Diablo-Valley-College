// main.cpp - Testing the addArray & AsmAddArray subroutines.

#include <iostream>
#include <time.h>
#include "addArray.h"
using namespace std;

int main()
{
	// Fill an array with pseudorandom integers.
	const unsigned ARRAY_SIZE = 10000;
	const unsigned LOOP_SIZE = 3000000;
	long array[ARRAY_SIZE];
	for(unsigned i = 0; i < ARRAY_SIZE; i++)
    array[i] = rand();

	long mval = 9999999999999999999;		// additive
	time_t startTime;
	time_t endTime;
	int n;

	// Test the C++ function:

	time(&startTime);

	for(n = 0; n < LOOP_SIZE; n++) 
		addArray(mval, array, ARRAY_SIZE);

	time(&endTime);
	cout << "Elapsed CPP time: " << long(endTime - startTime) << " seconds" << endl;

	// Test the Assembly language version:

	time(&startTime);

	for(n = 0; n < LOOP_SIZE; n++)
		AsmAddArray(mval, array, ARRAY_SIZE);

	time(&endTime);
	cout << "Elapsed ASM time: " << long(endTime - startTime) << " seconds" << endl;

	return 0;
}
