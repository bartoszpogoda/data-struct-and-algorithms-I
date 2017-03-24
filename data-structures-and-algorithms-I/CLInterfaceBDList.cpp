#include "CLInterface.h"
#include <sstream> 

using namespace std;

BDList* CLInterface::testBDList = nullptr;

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

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}

void CLInterface::viewPrintedBDList() {
	system("CLS");
	cout << "-- Aktualna zawartosc listy dwukierunkowej: --" << endl << endl;

	if (testBDList == nullptr)
		testBDList = new BDList();

	cout << testBDList->toString();

	cout << endl << endl << "> Powrot: Enter";
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

	cout << " > Element " << element << " dodany na pozycji " << index;

	cout << endl << endl << "> Powrot: Enter";
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
		cout << " > Nie znaleziono elementu o indeksie " << index;
	else {
		testBDList->deleteElementAt(index);
		cout << " > Element z pozycji " << index << " zostal usuniety.";
	}

	cout << endl << endl << "> Powrot: Enter";
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
		cout << " > Nie znaleziono elementu: " << element;
	else {
		cout << " > Element " << element << " wystapil na pozycji " << foundIndex;
	}

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}

