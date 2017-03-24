#include "CLInterface.h"
#include <conio.h>

using namespace std;

Timer CLInterface::timer = Timer();
FileReader CLInterface::fileReader = FileReader();
Printer CLInterface::printer = Printer();

void CLInterface::enterCLI() {
	viewMenuStructures();
}

void CLInterface::viewMenuStructures() {
	int selected = 0, max = 3, selectedDelta = 0;

	system("CLS");
	while (selected != max) {
		 do {
			if (selected + selectedDelta >= 0 && selected + selectedDelta <= max) selected += selectedDelta;
	
			system("CLS");
			cout << "-- Struktury danych: --" << endl << endl;
			cout << ((selected == 0) ? " > " : "   ") << "Tablica" << endl;
			cout << ((selected == 1) ? " > " : "   ") << "Lista" << endl;
			cout << ((selected == 2) ? " > " : "   ") << "Kopiec" << endl;
			cout << ((selected == 3) ? " > " : "   ") << "Wyjscie" << endl;
		} while ((selectedDelta = handleUserInput()) != 0);

		if (selected == 0) {
			viewMenuArray();
		}
		else if (selected == 1) {
			viewMenuBDList();
			/*
			Array myarray = Array();
			
			timer.startTimer();

			for (int i = 0; i < 50000; i++)
				myarray.addElementEnd(1);

			timer.endTimer();
			cout << "Time elapsed [us] is " << timer.timeMicroSeconds();
			cout << "Time elapsed [ms] is " << timer.timeMiliSeconds();
			cout << "Time elapsed [s] is " << timer.timeSeconds();*/

		}
		else if (selected == 2) {
			viewMenuHeap();
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