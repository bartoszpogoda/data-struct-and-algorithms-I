#include "CLInterface.h"

#include <sstream> 
#include <vector>
#include <algorithm>
#include <iterator> // for ostream_iterator
#include <time.h>

using namespace std;

PerformanceTester CLInterface::performanceTester = PerformanceTester();

void CLInterface::viewTestMenu() {
	int selected = 0, max = 3, selectedDelta = 0;

	system("CLS");
	while (selected != max) {
		do {
			if (selected + selectedDelta >= 0 && selected + selectedDelta <= max) selected += selectedDelta;

			system("CLS");
			cout << "-- Kopiec: --" << endl << endl;
			cout << ((selected == 0) ? " > " : "   ") << "Wykonaj eksperymenty na tablicy" << endl;
			cout << ((selected == 1) ? " > " : "   ") << "Wykonaj eksperymenty na liscie dwukierunkowej" << endl;
			cout << ((selected == 2) ? " > " : "   ") << "Wykonaj eksperymenty na kopcu" << endl;
		} while ((selectedDelta = handleUserInput()) != 0);

		if (selected == 0) {
			viewTestArray();

			cout << endl << endl << "> Powrot: Enter";
			handleUserInput();
		}
		else if (selected == 1) {
			viewTestBDList();

			cout << endl << endl << "> Powrot: Enter";
			handleUserInput();
		}
		else if (selected == 2) {
			viewTestHeap();

			cout << endl << endl << "> Powrot: Enter";
			handleUserInput();
		}
	}
}

void CLInterface::viewTestArray() {
	system("CLS");
	cout << "-- Eksperymenty na tablicy: --" << endl << endl;

	srand(time(NULL));
	//int minSize = 10000, maxSize = 50000, sizeIteration = 10000;
	int minSize = 1000, maxSize = 5000, sizeIteration = 250;

	//--------------------------------------1.1.
	cout << endl << "1.1.a) " << endl;
	for(int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.addElementToFrontOfArray(size, 0, 10, 100);

	cout << endl << "1.1.b)" << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration) 
		performanceTester.addElementToFrontOfArray(size, 100000, 1000000, 100);

	cout << endl << "1.1.c) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.addElementToFrontOfArray(size, 1294967295, 2147483647, 100);

	//--------------------------------------1.2.
	cout << endl << "1.2.a) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.addElementToTheEndOfArray(size, 0, 10, 100);

	cout << endl << "1.2.b)" << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.addElementToTheEndOfArray(size, 100000, 1000000, 100);

	cout << endl << "1.2.c) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.addElementToTheEndOfArray(size, 1294967295, 2147483647, 100);

	//--------------------------------------1.3.
	cout << endl << "1.3.a) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.addElementToTheRandomOfArray(size, 0, 10, 100);

	cout << endl << "1.3.b)" << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.addElementToTheRandomOfArray(size, 100000, 1000000, 100);

	cout << endl << "1.3.c) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.addElementToTheRandomOfArray(size, 1294967295, 2147483647, 100);

	//--------------------------------------1.4.
	cout << endl << "1.4.a) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.deleteElementFromTheFrontOfArray(size, 0, 10, 100);

	cout << endl << "1.4.b)" << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.deleteElementFromTheFrontOfArray(size, 100000, 1000000, 100);

	cout << endl << "1.4.c) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.deleteElementFromTheFrontOfArray(size, 1294967295, 2147483647, 100);

	//--------------------------------------1.5.
	cout << endl << "1.5.a) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.deleteElementFromTheEndOfArray(size, 0, 10, 100);

	cout << endl << "1.5.b)" << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.deleteElementFromTheEndOfArray(size, 100000, 1000000, 100);

	cout << endl << "1.5.c) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.deleteElementFromTheEndOfArray(size, 1294967295, 2147483647, 100);

	//--------------------------------------1.6.
	cout << endl << "1.6.a) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.deleteElementFromTheRandomOfArray(size, 0, 10, 100);

	cout << endl << "1.6.b)" << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.deleteElementFromTheRandomOfArray(size, 100000, 1000000, 100);

	cout << endl << "1.6.c) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.deleteElementFromTheRandomOfArray(size, 1294967295, 2147483647, 100);

	//--------------------------------------1.7.
	cout << endl << "1.7.a) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.findElementInArray(size, 0, 100);

	cout << endl << "1.7.b)" << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.findElementInArray(size, 100000, 100);

	cout << endl << "1.7.c) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.findElementInArray(size, 1294967295, 100);

}

void CLInterface::viewTestBDList() {
	system("CLS");
	cout << "-- Eksperymenty na liscie dwukierunkowej: --" << endl << endl;

	srand(time(NULL));
	//int minSize = 10000, maxSize = 50000, sizeIteration = 10000;
	int minSize = 1000, maxSize = 5000, sizeIteration = 250;

	//--------------------------------------1.1.
	cout << endl << "2.1.a) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.addElementToFrontOfBDList(size, 0, 10, 100);

	cout << endl << "2.1.b)" << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.addElementToFrontOfBDList(size, 100000, 1000000, 100);

	cout << endl << "2.1.c) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.addElementToFrontOfBDList(size, 1294967295, 2147483647, 100);

	//--------------------------------------1.2.
	cout << endl << "2.2.a) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.addElementToTheEndOfBDList(size, 0, 10, 100);

	cout << endl << "2.2.b)" << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.addElementToTheEndOfBDList(size, 100000, 1000000, 100);

	cout << endl << "2.2.c) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.addElementToTheEndOfBDList(size, 1294967295, 2147483647, 100);

	//--------------------------------------1.3.
	cout << endl << "2.3.a) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.addElementToTheRandomOfBDList(size, 0, 10, 100);

	cout << endl << "2.3.b)" << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.addElementToTheRandomOfBDList(size, 100000, 1000000, 100);

	cout << endl << "2.3.c) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.addElementToTheRandomOfBDList(size, 1294967295, 2147483647, 100);

	//--------------------------------------1.4.
	cout << endl << "2.4.a) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.deleteElementFromTheFrontOfBDList(size, 0, 10, 100);

	cout << endl << "2.4.b)" << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.deleteElementFromTheFrontOfBDList(size, 100000, 1000000, 100);

	cout << endl << "2.4.c) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.deleteElementFromTheFrontOfBDList(size, 1294967295, 2147483647, 100);

	//--------------------------------------1.5.
	cout << endl << "2.5.a) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.deleteElementFromTheEndOfBDList(size, 0, 10, 100);

	cout << endl << "2.5.b)" << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.deleteElementFromTheEndOfBDList(size, 100000, 1000000, 100);

	cout << endl << "2.5.c) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.deleteElementFromTheEndOfBDList(size, 1294967295, 2147483647, 100);

	//--------------------------------------1.6.
	cout << endl << "2.6.a) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.deleteElementFromTheRandomOfBDList(size, 0, 10, 100);

	cout << endl << "2.6.b)" << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.deleteElementFromTheRandomOfBDList(size, 100000, 1000000, 100);

	cout << endl << "2.6.c) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.deleteElementFromTheRandomOfBDList(size, 1294967295, 2147483647, 100);

	//--------------------------------------1.7.
	cout << endl << "2.7.a) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.findElementInBDList(size, 0, 100);

	cout << endl << "2.7.b)" << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.findElementInBDList(size, 100000, 100);

	cout << endl << "2.7.c) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.findElementInBDList(size, 1294967295, 100);

}

void CLInterface::viewTestHeap() {
	system("CLS");
	cout << "-- Eksperymenty na kopcu: --" << endl << endl;

	srand(time(NULL));
	//int minSize = 10000, maxSize = 50000, sizeIteration = 10000;
	int minSize = 1000, maxSize = 5000, sizeIteration = 250;

	//--------------------------------------3.1.
	cout << endl << "3.1.a) " << endl;
	cout << endl << "3.1.b)" << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.addElementToTheHeap(size, 0, 2147483647, 100);

	cout << endl << "3.1.b)" << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.addElementToTheHeap(size, 100000, 1000000, 100);

	cout << endl << "3.1.c) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.addElementToTheHeap(size, 1294967295, 2147483647, 100);

	//--------------------------------------3.2.
	cout << endl << "3.2.a) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.deleteRootFromTheHeap(size, 0, 10, 100);

	cout << endl << "3.2.b)" << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.deleteRootFromTheHeap(size, 100000, 1000000, 100);

	cout << endl << "3.2.c) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.deleteRootFromTheHeap(size, 1294967295, 2147483647, 100);

	//--------------------------------------3.3.
	cout << endl << "3.3.a) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.findElementInHeap(size, 0, 100);

	cout << endl << "3.3.b)" << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.findElementInHeap(size, 100000, 100);

	cout << endl << "3.3.c) " << endl;
	for (int size = minSize; size <= maxSize; size += sizeIteration)
		performanceTester.findElementInHeap(size, 1294967295, 100);

}
