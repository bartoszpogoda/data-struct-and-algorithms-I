#include "CLInterface.h"
#include "Array.h"
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <sstream> 

using namespace std;

long long int CLInterface::frequency = 0;
long long int CLInterface::start = 0;
long long int CLInterface::elapsed = 0;

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
			
			startTimer();

			for (int i = 0; i < 50000; i++)
				myarray.addElementEnd(1);

			endTimer();
			cout << "Time elapsed [ms] is " << timeMiliSeconds();

		
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

void CLInterface::startTimer() {
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);

	LARGE_INTEGER count;
	QueryPerformanceCounter(&count);
	start = ((long long int)count.QuadPart);
}

void CLInterface::endTimer() {

	LARGE_INTEGER count;
	QueryPerformanceCounter(&count);
	elapsed = ((long long int)count.QuadPart) - start;
}

std::string CLInterface::timeSeconds()
{
	stringstream str;
	str << fixed << setprecision(3) << (float)elapsed /
		frequency << endl;

	return str.str();
}

std::string CLInterface::timeMiliSeconds() {
	stringstream str;
	str << setprecision(0) << (1000.0 * elapsed) /
		frequency << endl;

	return str.str();
}

std::string CLInterface::timeMicroSeconds() {
	stringstream str;
	str << setprecision(0) << (1000000.0 * elapsed) /
		frequency << endl << endl;

	return str.str();
}
