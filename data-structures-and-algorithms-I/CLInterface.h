#pragma 
#include <iostream>
#include "Timer.h"
#include "FileReader.h"
#include "Printer.h"
#include "PerformanceTester.h"
#include "Array.h"
#include "BDList.h"
#include "Heap.h"
#include "BSTree.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13

class CLInterface {
private:
	static FileReader fileReader;
	static Printer printer;
	static PerformanceTester performanceTester;

	static Array* testArray; 
	static BDList* testBDList;
	static Heap* testHeap;
	static BSTree* testBSTree;

	CLInterface() {};
public:
	static void enterCLI(bool fileOutput);
	static int handleUserInput();

	static void viewMenuStructures();
	
	static void viewMenuArray();
	static void viewInputFilenameArray();
	static void viewPrintedArray();
	static void viewAddElementToArray();
	static void viewAddElementToArrayFront();
	static void viewAddElementToArrayEnd();
	static void viewDeleteElementFromArray();
	static void viewDeleteElementFromArrayFront();
	static void viewDeleteElementFromArrayEnd();
	static void viewFindElementInArray();

	static void viewMenuBDList();
	static void viewInputFilenameBDList();
	static void viewPrintedBDList();
	static void viewAddElementToBDList();
	static void viewAddElementToBDListFront();
	static void viewAddElementToBDListEnd();
	static void viewDeleteElementFromBDList();
	static void viewDeleteElementFromBDListFront();
	static void viewDeleteElementFromBDListEnd();
	static void viewFindElementInBDList();

	static void viewMenuHeap();
	static void viewInputFilenameHeap();
	static void viewPrintedHeap();
	static void viewPrintedHeapTable();
	static void viewAddElementToHeap();
	static void viewDeleteElementFromHeap();
	static void viewFindElementInHeap();

	static void viewMenuBSTree();
	static void viewInputFilenameBSTree();
	static void viewPrintedBSTree();
	static void viewAddElementToBSTree();
	static void viewDeleteElementFromBSTree();
	static void viewFindElementInBSTree();
	static void viewRotateLeftBSTree();
	static void viewRotateRightBSTree();
	static void viewPerformDSWBSTree();

	static void viewTestMenu();
	static void viewTestArray();
	static void viewTestBDList();
	static void viewTestHeap(); 
	static void viewTestBSTree();
};