#pragma once
#include <windows.h>
#include <iostream>
#include <iomanip>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13

class CLInterface {
private:
	CLInterface() {};
	static long long int frequency, start, elapsed;
public:
	static void enterCLI();
	static void viewStructures();
	static int handleUserInput();

	static long long int read_QPC();
};