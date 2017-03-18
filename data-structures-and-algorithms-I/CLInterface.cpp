#include "CLInterface.h"
#include <conio.h>
#include <iostream>
#include "Array.h"
#include <windows.h>
#include <iomanip>
#include <conio.h>

using namespace std;

void CLInterface::enterCLI() {
	viewStructures();
}

void CLInterface::viewStructures() {
	int selected = 0, max = 2, selectedDelta = 0;

	while (selected != max) {
		while ((selectedDelta = handleUserInput()) != 0) {
			if (selected + selectedDelta >= 0 && selected + selectedDelta <= max) selected += selectedDelta;

			system("CLS");
			cout << "-- Struktury danych: --" << endl << endl;
			cout << ((selected == 0) ? " > " : "   ") << "Tablica" << endl;
			cout << ((selected == 1) ? " > " : "   ") << "Lista" << endl;
			cout << ((selected == 2) ? " > " : "   ") << "Wyjscie" << endl;
		}

		if (selected == 0) {
			// enter funkcja widoku od tablicy
		}
		else if (selected == 1) {
			// enter funkcja widoku od listy
			Array myarray = Array();

			/*QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
			/*start = read_QPC();

			for (int i = 0; i < 50000; i++)
				myarray.addElementEnd(1);


			elapsed = read_QPC() - start;

			cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
				frequency << endl;
			cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
				frequency << endl;
			cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
				frequency << endl << endl;*/
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

long long int CLInterface::read_QPC() {
		LARGE_INTEGER count;
		QueryPerformanceCounter(&count);
		return((long long int)count.QuadPart);
}
