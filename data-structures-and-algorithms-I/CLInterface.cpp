#include "CLInterface.h"
#include "Array.h"
#include "BDList.h"
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <sstream> 
#include <limits>

using namespace std;

Timer CLInterface::timer = Timer();
FileReader CLInterface::fileReader = FileReader();
Array* CLInterface::testArray = nullptr;
BDList* CLInterface::testBDList = nullptr;

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
	}
}

void CLInterface::viewMenuArray() {
	int selected = 0, max = 5, selectedDelta = 0;

	system("CLS");
	while (selected != max) {
		do {
			if (selected + selectedDelta >= 0 && selected + selectedDelta <= max) selected += selectedDelta;

			system("CLS");
			cout << "-- Tablica: --" << endl << endl;
			cout << ((selected == 0) ? " > " : "   ") << "Wczytaj z pliku" << endl;
			cout << ((selected == 1) ? " > " : "   ") << "Wypisz tablice na ekran" << endl;
			cout << ((selected == 2) ? " > " : "   ") << "Dodaj element" << endl;
			cout << ((selected == 3) ? " > " : "   ") << "Usun element" << endl;
			cout << ((selected == 4) ? " > " : "   ") << "Znajdz element" << endl;
			cout << ((selected == 5) ? " > " : "   ") << "Wyjscie" << endl;
		} while ((selectedDelta = handleUserInput()) != 0);

		if (selected == 0) {
			viewInputFilenameArray();
		}
		else if (selected == 1) {
			viewPrintedArray();
		}
		else if (selected == 2) {
			viewAddElementToArray();
			viewPrintedArray();
		}
		else if (selected == 3) {
			viewDeleteElementFromArray();
			viewPrintedArray();
		}
		else if (selected == 4) {
			viewFindElementInArray();
			viewPrintedArray();
		}
	}

	delete testArray;
	testArray = nullptr;
}

void CLInterface::viewInputFilenameArray() {
	string filename = " ";

	system("CLS");
	cout << "-- Wczytaj z pliku: --" << endl << endl;
	cout << " > Podaj nazwe pliku: ";
	cin >> filename;

	cout << "Wynik: " << fileReader.readArray(filename, CLInterface::testArray);
	handleUserInput();
}


void CLInterface::viewPrintedArray() {

	system("CLS");
	cout << "-- Aktualna zawartosc tablicy: --" << endl << endl;
	
	if (testArray == nullptr)
		testArray = new Array();

	cout << testArray->toString();

	handleUserInput();
}

void CLInterface::viewAddElementToArray() {
	system("CLS");
	type element;
	int index;

	cout << "-- Dodaj element do tablicy: --" << endl << endl;
	cout << " > Wprowadz element (liczba calkowita): ";
	cin >> element;
	cout << " > Wprowadz indeks: ";
	cin >> index;

	if (testArray == nullptr)
		testArray = new Array();

	if (index < 0 || index >= testArray->size())
		index = testArray->size();

	testArray->addElementAt(element, index);

	cout << " > Element " << element << " dodany na pozycji " << index << endl;

	handleUserInput();
}

void CLInterface::viewDeleteElementFromArray() {
	system("CLS");

	if (testArray == nullptr) {
		cout << " > Tablica nie zostala zainicjalizowana" << endl;
		handleUserInput();
		return;
	}

	int index;

	cout << "-- Usun element z tablicy: --" << endl << endl;
	cout << " > Wprowadz indeks: ";
	cin >> index;

	
	if (index < 0 || index >= testArray->size())
		cout << " > Nie znaleziono elementu o indeksie " << index << endl;
	else {
		testArray->deleteElementAt(index);
		cout << " > Element z pozycji " << index << " zostal usuniety." << endl;
	}
	
	handleUserInput();
}

void CLInterface::viewFindElementInArray() {
	system("CLS");
	
	if (testArray == nullptr) {
		cout << " > Tablica nie zostala zainicjalizowana" << endl;
		handleUserInput();
		return;
	}
	
	int element;

	cout << "-- Znajdz indeks pierwszego wystapienia elementu w tablicy: --" << endl << endl;
	cout << " > Wprowadz element (liczba calkowita): ";
	cin >> element;

	
	int foundIndex = testArray->findElement(element);

	if (foundIndex == -1)
		cout << " > Nie znaleziono elementu: " << element << endl;
	else {
		cout << " > Element " << element << " wystapil na pozycji " << foundIndex << endl;
	}

	handleUserInput();
}

void CLInterface::viewMenuBDList() {
	int selected = 0, max = 5, selectedDelta = 0;

	system("CLS");
	while (selected != max) {
		do {
			if (selected + selectedDelta >= 0 && selected + selectedDelta <= max) selected += selectedDelta;

			system("CLS");
			cout << "-- Lista dwukierunkowa: --" << endl << endl;
			cout << ((selected == 0) ? " > " : "   ") << "Wczytaj z pliku" << endl;
			cout << ((selected == 1) ? " > " : "   ") << "Wypisz liste na ekran" << endl;
			cout << ((selected == 2) ? " > " : "   ") << "Dodaj element" << endl;
			cout << ((selected == 3) ? " > " : "   ") << "Usun element" << endl;
			cout << ((selected == 4) ? " > " : "   ") << "Znajdz element" << endl;
			cout << ((selected == 5) ? " > " : "   ") << "Wyjscie" << endl;
		} while ((selectedDelta = handleUserInput()) != 0);

		if (selected == 0) {
			viewInputFilenameBDList();
		}
		else if (selected == 1) {
			viewPrintedBDList();
		}
		else if (selected == 2) {
			viewAddElementToBDList();
			viewPrintedBDList();
		}
		else if (selected == 3) {
			viewDeleteElementFromBDList();
			viewPrintedBDList();
		}
		else if (selected == 4) {
			viewFindElementInBDList();
			viewPrintedBDList();
		}
	}

	delete testBDList;
	testBDList = nullptr;
}

void CLInterface::viewInputFilenameBDList() {
	string filename = " ";

	system("CLS");
	cout << "-- Wczytaj z pliku: --" << endl << endl;
	cout << " > Podaj nazwe pliku: ";
	cin >> filename;

	cout << "Wynik: " << fileReader.readBDList(filename, CLInterface::testBDList);
	handleUserInput();
}

void CLInterface::viewPrintedBDList() {
	system("CLS");
	cout << "-- Aktualna zawartosc listy dwukierunkowej: --" << endl << endl;

	if (testBDList == nullptr)
		testBDList = new BDList();

	cout << testBDList->toString();

	handleUserInput();
}

void CLInterface::viewAddElementToBDList() {
	system("CLS");
	type element;
	int index;

	cout << "-- Dodaj element do listy dwukierunkowej: --" << endl << endl;
	cout << " > Wprowadz element (liczba calkowita): ";
	cin >> element;
	cout << " > Wprowadz indeks: ";
	cin >> index;

	if (testBDList == nullptr)
		testBDList = new BDList();

	if (index < 0 || index >= testBDList->size())
		index = testBDList->size();

	testBDList->addElementAt(element, index);

	cout << " > Element " << element << " dodany na pozycji " << index << endl;

	handleUserInput();
}

void CLInterface::viewDeleteElementFromBDList() {
	system("CLS");

	if (testBDList == nullptr) {
		cout << " > Lista nie zostala zainicjalizowana" << endl;
		handleUserInput();
		return;
	}

	int index;

	cout << "-- Usun element z listy: --" << endl << endl;
	cout << " > Wprowadz indeks: ";
	cin >> index;


	if (index < 0 || index >= testBDList->size())
		cout << " > Nie znaleziono elementu o indeksie " << index << endl;
	else {
		testBDList->deleteElementAt(index);
		cout << " > Element z pozycji " << index << " zostal usuniety." << endl;
	}

	handleUserInput();
}

void CLInterface::viewFindElementInBDList() {
	system("CLS");

	if (testBDList == nullptr) {
		cout << " > Lista dwukierunkowa nie zostala zainicjalizowana" << endl;
		handleUserInput();
		return;
	}

	int element;

	cout << "-- Znajdz indeks pierwszego wystapienia elementu w liscie dwukierunkowej: --" << endl << endl;
	cout << " > Wprowadz element (liczba calkowita): ";
	cin >> element;


	int foundIndex = testBDList->findElement(element);

	if (foundIndex == -1)
		cout << " > Nie znaleziono elementu: " << element << endl;
	else {
		cout << " > Element " << element << " wystapil na pozycji " << foundIndex << endl;
	}

	handleUserInput();
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