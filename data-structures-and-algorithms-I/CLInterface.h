#pragma 
#include <iostream>
#include "Timer.h"
#include "FileReader.h"
#include "Array.h"
#include "BDList.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13

class CLInterface {
private:
	static Timer timer;
	static FileReader fileReader;

	static Array *testArray; 
	static BDList *testBDList;

	CLInterface() {};
public:
	static void enterCLI();
	static void viewMenuStructures();

	static void viewMenuArray();
	static void viewInputFilenameArray();
	static void viewPrintedArray();
	static void viewAddElementToArray();
	static void viewDeleteElementFromArray();
	static void viewFindElementInArray();


	static void viewMenuBDList();
	static void viewInputFilenameBDList();
	static void viewPrintedBDList();
	static void viewAddElementToBDList();
	static void viewDeleteElementFromBDList();
	static void viewFindElementInBDList();

	static int handleUserInput();
};