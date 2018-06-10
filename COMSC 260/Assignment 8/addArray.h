// addArray.h

extern "C"
{
	void AsmAddArray(long mval, long array[], long arraySize);
	// Assembly language version

	void addArray(long mval, long array[], long arraySize);
	// C++ version
}