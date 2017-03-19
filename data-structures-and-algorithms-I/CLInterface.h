#pragma 
#include <iostream>
#include "Timer.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13

class CLInterface {
private:
	static Timer timer;

	CLInterface() {};
public:
	static void enterCLI();
	static void viewMenuStructures();
	static void viewMenuArray();

	static int handleUserInput();
};