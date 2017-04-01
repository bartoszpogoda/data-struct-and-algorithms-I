#include "CLInterface.h"
#include <conio.h>

using namespace std;

FileReader CLInterface::fileReader = FileReader();
Printer CLInterface::printer = Printer();

void CLInterface::enterCLI(bool fileOutput) {
	if (fileOutput) {
		performanceTester.setFileOutput(true);
		CLInterface::viewTestArray();
		CLInterface::viewTestBDList();
		CLInterface::viewTestHeap();
	} 
	else
		viewMenuStructures();
}

void CLInterface::viewMenuStructures() {
	int selected = 0, max = 5, selectedDelta = 0;

	system("CLS");
	while (selected != max) {
		 do {
			 if (selected + selectedDelta < 0)
				 selected = max;
			 else if (selected + selectedDelta > max)
				 selected = 0;
			 else
				 selected += selectedDelta;
	
			system("CLS");
			cout << "-- Struktury danych: --" << endl << endl;
			cout << ((selected == 0) ? " > " : "   ") << "Tablica" << endl;
			cout << ((selected == 1) ? " > " : "   ") << "Lista" << endl;
			cout << ((selected == 2) ? " > " : "   ") << "Kopiec" << endl;
			cout << ((selected == 3) ? " > " : "   ") << "Drzewo czerwono-czarne" << endl;
			cout << ((selected == 4) ? " > " : "   ") << "Eksperymenty" << endl;
			cout << ((selected == 5) ? " > " : "   ") << "Wyjscie" << endl;
		} while ((selectedDelta = handleUserInput()) != 0);

		if (selected == 0) {
			viewMenuArray();
		}
		else if (selected == 1) {
			viewMenuBDList();
		}
		else if (selected == 2) {
			viewMenuHeap();
		}
		else if (selected == 3) {
			viewMenuBSTree();
		}
		else if (selected == 4) {
			viewTestMenu();
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