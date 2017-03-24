#pragma once
#pragma once
#include <iostream>

class Timer {
private:
	long long int frequency, start, elapsed, memory;
public:
	Timer() : frequency(0), start(0), elapsed(0), memory(0) { };
	long long int read_QPC();

	void startTimer();
	void endTimer();
	void resetMemory() { memory = 0; }
	void divideMemory(int divisor) { memory /= divisor; }

	std::string timeSeconds();
	std::string timeMiliSeconds();
	std::string timeMicroSeconds();

	std::string timeSecondsMemory();
	std::string timeMiliSecondsMemory();
	std::string timeMicroSecondsMemory();

};