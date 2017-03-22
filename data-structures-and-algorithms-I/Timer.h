#pragma once
#pragma once
#include <iostream>

class Timer {
private:
	long long int frequency, start, elapsed;
public:
	Timer() : frequency(0), start(0), elapsed(0) { };
	long long int read_QPC();

	void startTimer();
	void endTimer();

	std::string timeSeconds();
	std::string timeMiliSeconds();
	std::string timeMicroSeconds();

};