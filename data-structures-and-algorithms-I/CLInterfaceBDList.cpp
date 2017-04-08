#include "CLInterface.h"
#include <sstream> 

using namespace std;

BDList* CLInterface::testBDList = nullptr;

void CLInterface::viewMenuBDList() {
	int selected = 0, max = 9, selectedDelta = 0;

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
			cout << "-- Lista dwukierunkowa: --" << endl << endl;
			cout << ((selected == 0) ? " > " : "   ") << "Wczytaj z pliku" << endl;
			cout << ((selected == 1) ? " > " : "   ") << "Wypisz liste na ekran" << endl;
			cout << "   " << "Dodaj element:" << endl;
			cout << ((selected == 2) ? "    > " : "      ") << "Indeks" << endl;
			cout << ((selected == 3) ? "    > " : "      ") << "Poczatek" << endl;
			cout << ((selected == 4) ? "    > " : "      ") << "Koniec" << endl;
			cout << "   " << "Usun element:" << endl;
			cout << ((selected == 5) ? "    > " : "      ") << "Indeks" << endl;
			cout << ((selected == 6) ? "    > " : "      ") << "Poczatek" << endl;
			cout << ((selected == 7) ? "    > " : "      ") << "Koniec" << endl;
			cout << ((selected == 8) ? " > " : "   ") << "Znajdz element" << endl << endl;
			cout << ((selected == 9) ? " > " : "   ") << "Wyjscie" << endl;
		} while ((selectedDelta = handleUserInput()) != 0);

		if (selected == 0) {
			viewInputFilenameBDList();
			viewPrintedBDList();
		}
		else if (selected == 1) {
			viewPrintedBDList();
		}
		else if (selected == 2) {
			viewAddElementToBDList();
			viewPrintedBDList();
		}
		else if (selected == 3) {
			viewAddElementToBDListFront();
			viewPrintedBDList();
		}
		else if (selected == 4) {
			viewAddElementToBDListEnd();
			viewPrintedBDList();
		}
		else if (selected == 5) {
			viewDeleteElementFromBDList();
			viewPrintedBDList();
		}
		else if (selected == 6) {
			viewDeleteElementFromBDListFront();
			viewPrintedBDList();
		}
		else if (selected == 7) {
			viewDeleteElementFromBDListEnd();
			viewPrintedBDList();
		}
		else if (selected == 8) {
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

	testBDList->addAt(element, index);

	cout << " > Element " << element << " dodany na pozycji " << index;

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}

void CLInterface::viewAddElementToBDListFront() {
	system("CLS");
	type element;

	cout << "-- Dodaj element do listy dwukierunkowej - poczatek: --" << endl << endl;
	cout << " > Wprowadz element (liczba calkowita): ";
	cin >> element;

	if (testBDList == nullptr)
		testBDList = new BDList();


	testBDList->addFront(element);

	cout << " > Element " << element << " dodany na pierwszej pozycji";

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}


void CLInterface::viewAddElementToBDListEnd() {
	system("CLS");
	type element;

	cout << "-- Dodaj element do listy dwukierunkowej - koniec: --" << endl << endl;
	cout << " > Wprowadz element (liczba calkowita): ";
	cin >> element;

	if (testBDList == nullptr)
		testBDList = new BDList();

	testBDList->addEnd(element);

	cout << " > Element " << element << " dodany na ostatniej pozycji";

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}


void CLInterface::viewDeleteElementFromBDList() {
	system("CLS");

	if (testBDList == nullptr || testBDList->size() == 0) {
		return;
	}

	int index;

	cout << "-- Usun element z listy dwukierunkowej: --" << endl << endl;
	cout << " > Wprowadz indeks: ";
	cin >> index;


	if (index < 0 || index >= testBDList->size())
		cout << " > Nie znaleziono elementu o indeksie " << index;
	else {
		testBDList->deleteAt(index);
		cout << " > Element z pozycji " << index << " zostal usuniety.";
	}

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}

void CLInterface::viewDeleteElementFromBDListFront() {
	system("CLS");

	if (testBDList == nullptr || testBDList->size() == 0) {
		return;
	}

	cout << "-- Usun element z listy dwukierunkowej - poczatek: --" << endl << endl;

	char decision;
	cout << " > Potwierdzenie operacji T/N: ";
	cin >> decision;

	if (decision == 'T' || decision == 't') {
		testBDList->deleteFront();
		cout << " > Element z poczatkowej pozycji zostal usuniety.";
	}
	else {
		cout << " > Operacja anulowana";
	}

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}

void CLInterface::viewDeleteElementFromBDListEnd() {
	system("CLS");

	if (testBDList == nullptr || testBDList->size() == 0) {
		return;
	}

	cout << "-- Usun element z listy dwukierunkowej - koniec: --" << endl << endl;

	char decision;
	cout << " > Potwierdzenie operacji T/N: ";
	cin >> decision;

	if (decision == 'T' || decision == 't') {
		testBDList->deleteEnd();
		cout << " > Element z ostatniej pozycji zostal usuniety.";
	}
	else {
		cout << " > Operacja anulowana";
	}

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}

void CLInterface::viewFindElementInBDList() {
	system("CLS");

	if (testBDList == nullptr || testBDList->size() == 0) {
		return;
	}

	int element;

	cout << "-- Znajdz indeks pierwszego wystapienia elementu w liscie dwukierunkowej: --" << endl << endl;
	cout << " > Wprowadz element (liczba calkowita): ";
	cin >> element;


	int foundIndex = testBDList->find(element);

	if (foundIndex == -1)
		cout << " > Nie znaleziono elementu: " << element;
	else {
		cout << " > Element " << element << " wystapil na pozycji " << foundIndex;
	}

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}

