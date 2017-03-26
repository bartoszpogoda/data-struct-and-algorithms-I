#pragma once
#include <iostream>

class Timer {
private:
	volatile long long int frequency, start, elapsed, memory, operationCounter;
public:
	Timer() : frequency(0), start(0), elapsed(0), memory(0), operationCounter(0) { };
	long long int read_QPC();

	void startTimer();
	void endTimer();
	void resetMemory();
	void divideMemory(int divisor) { memory /= divisor; }

	std::string timeSeconds();
	std::string timeMiliSeconds();
	std::string timeMicroSeconds();

	std::string timeSecondsMemory();
	std::string timeMiliSecondsMemory();
	std::string timeMicroSecondsMemory();

};