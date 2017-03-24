#pragma once
#include "Timer.h"
#include "Type.h"

class PerformanceTester {
	Timer timer;
public:
	PerformanceTester() : timer(Timer()) { };

	void addElementToFrontOfArray(int arraySize, type valuesMin, type valuesMax, int iterations);
};