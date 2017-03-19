#include "Timer.h"

#include <iostream>
#include <windows.h>
#include <iomanip>
#include <sstream> 

long long int Timer::read_QPC() {
	LARGE_INTEGER count;
	QueryPerformanceCounter(&count);
	return((long long int)count.QuadPart);
}

void Timer::startTimer() {
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);

	LARGE_INTEGER count;
	QueryPerformanceCounter(&count);
	start = ((long long int)count.QuadPart);
}

void Timer::endTimer() {
	LARGE_INTEGER count;
	QueryPerformanceCounter(&count);
	elapsed = ((long long int)count.QuadPart) - start;
}

std::string Timer::timeSeconds() {
	std::stringstream str;
	str << std::fixed << std::setprecision(3) << (float)elapsed /
		frequency;

	return str.str();
}

std::string Timer::timeMiliSeconds() {
	std::stringstream str;
	str << std::setprecision(0) << (1000.0 * elapsed) /
		frequency;

	return str.str();
}

std::string Timer::timeMicroSeconds() {
	std::stringstream  str;
	str << std::setprecision(0) << (1000000.0 * elapsed) /
		frequency;

	return str.str();
}