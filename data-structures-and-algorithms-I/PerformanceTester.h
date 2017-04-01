#pragma once
#include "Timer.h"
#include "Type.h"
#include <random>

class PerformanceTester {
	Timer timer;
	bool fileOutput;
	std::mt19937 gen; 
	std::uniform_int_distribution<> bigNumberDist; 
public:
	PerformanceTester() : timer(Timer()), fileOutput(false), gen(123456789), bigNumberDist(0, 2147483646) { };
	void setFileOutput(bool fileOutput) { this->fileOutput = fileOutput; }

	// array
	void addElementToFrontOfArray(int arraySize, type valuesMin, type valuesMax, int iterations);
	void addElementToTheEndOfArray(int arraySize, type valuesMin, type valuesMax, int iterations);
	void addElementToTheRandomOfArray(int arraySize, type valuesMin, type valuesMax, int iterations);

	void deleteElementFromTheFrontOfArray(int arraySize, type valuesMin, type valuesMax, int iterations);
	void deleteElementFromTheEndOfArray(int arraySize, type valuesMin, type valuesMax, int iterations);
	void deleteElementFromTheRandomOfArray(int arraySize, type valuesMin, type valuesMax, int iterations);

	void findElementInArray(int arraySize, type valuesMin, int iterations);

	// bd list
	void addElementToFrontOfBDList(int arraySize, type valuesMin, type valuesMax, int iterations);
	void addElementToTheEndOfBDList(int arraySize, type valuesMin, type valuesMax, int iterations);
	void addElementToTheRandomOfBDList(int arraySize, type valuesMin, type valuesMax, int iterations);

	void deleteElementFromTheFrontOfBDList(int arraySize, type valuesMin, type valuesMax, int iterations);
	void deleteElementFromTheEndOfBDList(int arraySize, type valuesMin, type valuesMax, int iterations);
	void deleteElementFromTheRandomOfBDList(int arraySize, type valuesMin, type valuesMax, int iterations);

	void findElementInBDList(int arraySize, type valuesMin, int iterations);

	//heap
	void addElementToTheHeap(int arraySize, type valuesMin, type valuesMax, int iterations);
	void deleteRootFromTheHeap(int arraySize, type valuesMin, type valuesMax, int iterations);
	void findElementInHeap(int arraySize, type valuesMin, int iterations);

};