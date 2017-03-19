#include "CLInterface.h"
#include "Array.h"
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <sstream> 

using namespace std;

Timer CLInterface::timer = Timer();

void CLInterface::enterCLI() {
	viewMenuStructures();
}

void CLInterface::viewMenuStructures() {
	int selected = 0, max = 2, selectedDelta = 0;

	system("CLS");
	while (selected != max) {
		 do {
			if (selected + selectedDelta >= 0 && selected + selectedDelta <= max) selected += selectedDelta;
	
			system("CLS");
			cout << "-- Struktury danych: --" << endl << endl;
			cout << ((selected == 0) ? " > " : "   ") << "Tablica" << endl;
			cout << ((selected == 1) ? " > " : "   ") << "Lista" << endl;
			cout << ((selected == 2) ? " > " : "   ") << "Wyjscie" << endl;
		} while ((selectedDelta = handleUserInput()) != 0);

		if (selected == 0) {
			viewMenuArray();
		}
		else if (selected == 1) {
			// enter funkcja widoku od listy
			Array myarray = Array();
			
			timer.startTimer();

			for (int i = 0; i < 50000; i++)
				myarray.addElementEnd(1);

			timer.endTimer();
			cout << "Time elapsed [us] is " << timer.timeMicroSeconds();
			cout << "Time elapsed [ms] is " << timer.timeMiliSeconds();
			cout << "Time elapsed [s] is " << timer.timeSeconds();

		
		}
	}
}

void CLInterface::viewMenuArray() {
	int selected = 0, max = 2, selectedDelta = 0;

	system("CLS");
	while (selected != max) {
		do {
			if (selected + selectedDelta >= 0 && selected + selectedDelta <= max) selected += selectedDelta;

			system("CLS");
			cout << "-- Tablica: --" << endl << endl;
			cout << ((selected == 0) ? " > " : "   ") << "Zrob to" << endl;
			cout << ((selected == 1) ? " > " : "   ") << "Zrob tamto" << endl;
			cout << ((selected == 2) ? " > " : "   ") << "Wyjscie" << endl;
		} while ((selectedDelta = handleUserInput()) != 0);

		if (selected == 0) {
			// ...
		}
		else if (selected == 1) {
			// ...
		}
	}
}

int CLInterface::handleUserInput() {
	int c = 0;

	while ((c = getch())) {
		if (c == KEY_UP) {
			return -1;
		}
		else if (c == KEY_DOWN) {
			return 1;
		}
		else if (c == ENTER) {
			return 0;
		}

		c = 0;
	}
}