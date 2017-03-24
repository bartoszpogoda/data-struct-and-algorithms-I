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
		}
		else if (selected == 1) {
			viewTestBDList();
		}
		else if (selected == 2) {
			viewTestHeap();
		}
	}
}

void CLInterface::viewTestArray() {
	system("CLS");
	cout << "-- Eksperymenty na tablicy: --" << endl << endl;
	
	cout << "a) " << endl;
	performanceTester.addElementToFrontOfArray(250, 0, 10, 100);
	performanceTester.addElementToFrontOfArray(500, 0, 10, 100);
	performanceTester.addElementToFrontOfArray(750, 0, 10, 100);
	performanceTester.addElementToFrontOfArray(1000, 0, 10, 100);
	performanceTester.addElementToFrontOfArray(1250, 0, 10, 100);
	performanceTester.addElementToFrontOfArray(1550, 0, 10, 100);

	cout << "b) " << endl;
	performanceTester.addElementToFrontOfArray(250, 100, 1000, 100);
	performanceTester.addElementToFrontOfArray(500, 100, 1000, 100);
	performanceTester.addElementToFrontOfArray(750, 100, 1000, 100);
	performanceTester.addElementToFrontOfArray(1000, 100, 1000, 100);
	performanceTester.addElementToFrontOfArray(1250, 100, 1000, 100);
	performanceTester.addElementToFrontOfArray(1550, 100, 1000, 100);

	cout << "c) " << endl;
	performanceTester.addElementToFrontOfArray(250, 1294967295, 2147483647, 100);
	performanceTester.addElementToFrontOfArray(500, 1294967295, 2147483647, 100);
	performanceTester.addElementToFrontOfArray(750, 1294967295, 2147483647, 100);
	performanceTester.addElementToFrontOfArray(1000, 1294967295, 2147483647, 100);
	performanceTester.addElementToFrontOfArray(1250, 1294967295, 2147483647, 100);
	performanceTester.addElementToFrontOfArray(1550, 1294967295, 2147483647, 100);


	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}

void CLInterface::viewTestBDList() {

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}

void CLInterface::viewTestHeap() {

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}
