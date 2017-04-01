#include "CLInterface.h"
#include <sstream> 

using namespace std;

Array* CLInterface::testArray = nullptr;

void CLInterface::viewMenuArray() {
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
			cout << "-- Tablica: --" << endl << endl;
			cout << ((selected == 0) ? " > " : "   ") << "Wczytaj z pliku" << endl;
			cout << ((selected == 1) ? " > " : "   ") << "Wypisz tablice na ekran" << endl;
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
			viewInputFilenameArray();
			viewPrintedArray();
		}
		else if (selected == 1) {
			viewPrintedArray();
		}
		else if (selected == 2) {
			viewAddElementToArray();
			viewPrintedArray();
		}
		else if (selected == 3) {
			viewAddElementToArrayFront();
			viewPrintedArray();
		}
		else if (selected == 4) {
			viewAddElementToArrayEnd();
			viewPrintedArray();
		}
		else if (selected == 5) {
			viewDeleteElementFromArray();
			viewPrintedArray();
		}
		else if (selected == 6) {
			viewDeleteElementFromArrayFront();
			viewPrintedArray();
		}
		else if (selected == 7) {
			viewDeleteElementFromArrayEnd();
			viewPrintedArray();
		}
		else if (selected == 8) {
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

	cout << "Wynik: " << fileReader.readArray(filename, CLInterface::testArray) << endl << endl;

	cout << "> Powrot: Enter";
	handleUserInput();
}


void CLInterface::viewPrintedArray() {

	system("CLS");
	cout << "-- Aktualna zawartosc tablicy: --" << endl << endl;

	if (testArray == nullptr)
		testArray = new Array();

	cout << testArray->toString() << endl << endl;

	cout << "> Powrot: Enter";
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

	testArray->addAt(element, index);

	cout << " > Element " << element << " dodany na pozycji " << index << endl << endl;

	cout << "> Powrot: Enter";
	handleUserInput();
}

void CLInterface::viewAddElementToArrayFront() {
	system("CLS");
	type element;

	cout << "-- Dodaj element do tablicy - poczatek: --" << endl << endl;
	cout << " > Wprowadz element (liczba calkowita): ";
	cin >> element;

	if (testArray == nullptr)
		testArray = new Array();

	testArray->addFront(element);

	cout << " > Element " << element << " dodany na pierwszej pozycji " << endl << endl;

	cout << "> Powrot: Enter";
	handleUserInput();
}

void CLInterface::viewAddElementToArrayEnd() {
	system("CLS");
	type element;

	cout << "-- Dodaj element do tablicy - koniec: --" << endl << endl;
	cout << " > Wprowadz element (liczba calkowita): ";
	cin >> element;

	if (testArray == nullptr)
		testArray = new Array();

	testArray->addEnd(element);

	cout << " > Element " << element << " dodany na ostatniej pozycji " << endl << endl;

	cout << "> Powrot: Enter";
	handleUserInput();
}

void CLInterface::viewDeleteElementFromArray() {
	system("CLS");

	if (testArray == nullptr || testArray->size() == 0) {
		return;
	}

	int index;

	cout << "-- Usun element z tablicy: --" << endl << endl;
	cout << " > Wprowadz indeks: ";
	cin >> index;


	if (index < 0 || index >= testArray->size())
		cout << " > Nie znaleziono elementu o indeksie " << index << endl << endl;
	else {
		testArray->deleteAt(index);
		cout << " > Element z pozycji " << index << " zostal usuniety." << endl << endl;
	}

	cout << "> Powrot: Enter";
	handleUserInput();
}

void CLInterface::viewDeleteElementFromArrayFront() {
	system("CLS");

	if (testArray == nullptr ||  testArray->size() == 0) {
		return;
	}

	cout << "-- Usun element z tablicy - poczatek: --" << endl << endl;

	char decision;

	cout << " > Potwierdzenie operacji T/N: ";
	cin >> decision;

	if (decision == 'T' || decision == 't') {
		testArray->deleteFront();
		cout << " > Element z poczatkowej pozycji zostal usuniety.";
	}
	else {
		cout << " > Operacja anulowana";
	}

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}

void CLInterface::viewDeleteElementFromArrayEnd() {
	system("CLS");

	if (testArray == nullptr || testArray->size() == 0) {
		return;
	}

	cout << "-- Usun element z tablicy - koniec: --" << endl << endl;

	char decision;

	cout << " > Potwierdzenie operacji T/N: ";
	cin >> decision;

	if (decision == 'T' || decision == 't') {
		testArray->deleteEnd();
		cout << " > Element z koncowej pozycji zostal usuniety.";
	}
	else {
		cout << " > Operacja anulowana" << endl;
	}

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}

void CLInterface::viewFindElementInArray() {
	system("CLS");

	if (testArray == nullptr || testArray->size() == 0) {
		return;
	}

	int element;

	cout << "-- Znajdz indeks pierwszego wystapienia elementu w tablicy: --" << endl << endl;
	cout << " > Wprowadz element (liczba calkowita): ";
	cin >> element;


	int foundIndex = testArray->find(element);

	if (foundIndex == -1)
		cout << " > Nie znaleziono elementu: " << element << endl << endl;
	else {
		cout << " > Element " << element << " wystapil na pozycji " << foundIndex << endl << endl;
	}

	cout << "> Powrot: Enter";
	handleUserInput();
}