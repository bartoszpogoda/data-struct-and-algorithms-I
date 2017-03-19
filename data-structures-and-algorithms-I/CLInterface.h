#pragma once
#include <iostream>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13

class CLInterface {
private:
	static long long int frequency, start, elapsed;
	CLInterface() {};
public:
	static void enterCLI();
	static void viewStructures();

	static int handleUserInput();

	static long long int read_QPC();

	static void startTimer();
	static void endTimer();

	static std::string timeSeconds();
	static std::string timeMiliSeconds();
	static std::string timeMicroSeconds();

};