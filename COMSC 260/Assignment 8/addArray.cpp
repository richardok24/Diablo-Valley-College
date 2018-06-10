// addArray.cpp

#include "addArray.h"

void addArray(long mval, long array[], long arraySize)
{
	for(int i = 0; i < arraySize; i++)
		array[i] += mval;
}
