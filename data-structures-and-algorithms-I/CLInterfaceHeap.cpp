#include "CLInterface.h"
#include <sstream> 

using namespace std;

Heap* CLInterface::testHeap = nullptr;

void CLInterface::viewMenuHeap() {
	int selected = 0, max = 6, selectedDelta = 0;

	system("CLS");
	while (selected != max) {
		do {
			if (selected + selectedDelta >= 0 && selected + selectedDelta <= max) selected += selectedDelta;

			system("CLS");
			cout << "-- Kopiec: --" << endl << endl;
			cout << ((selected == 0) ? " > " : "   ") << "Wczytaj z pliku" << endl;
			cout << ((selected == 1) ? " > " : "   ") << "Wypisz kopiec na ekran" << endl;
			cout << ((selected == 2) ? " > " : "   ") << "Wypisz kopiec na ekran - tablica" << endl;
			cout << ((selected == 3) ? " > " : "   ") << "Dodaj element" << endl;
			cout << ((selected == 4) ? " > " : "   ") << "Usun korzen" << endl;
			cout << ((selected == 5) ? " > " : "   ") << "Znajdz element" << endl;
			cout << ((selected == 6) ? " > " : "   ") << "Wyjscie" << endl;
		} while ((selectedDelta = handleUserInput()) != 0);

		if (selected == 0) {
			viewInputFilenameHeap();
		}
		else if (selected == 1) {
			viewPrintedHeap();
		}
		else if (selected == 2) {
			viewPrintedHeapTable();
		}
		else if (selected == 3) {
			viewAddElementToHeap();
			viewPrintedHeap();
		}
		else if (selected == 4) {
			viewDeleteElementFromHeap();
			viewPrintedHeap();
		}
		else if (selected == 5) {
			viewFindElementInHeap();
			viewPrintedHeapTable();
		}
	}

	delete testHeap;
	testHeap = nullptr;
}

void CLInterface::viewInputFilenameHeap() {
	string filename = " ";

	system("CLS");
	cout << "-- Wczytaj z pliku: --" << endl << endl;
	cout << " > Podaj nazwe pliku: ";
	cin >> filename;

	cout << "Wynik: " << fileReader.readHeap(filename, CLInterface::testHeap);

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}

void CLInterface::viewPrintedHeap() {
	system("CLS");
	cout << "-- Aktualna zawartosc kopca: --" << endl << endl;

	if (testHeap == nullptr)
		testHeap = new Heap();

	if (testHeap->size() == 0) {
		cout << testHeap->toStringTable();
	}
	else {
		printer.print_heap(testHeap->getVector());
	}

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}

void CLInterface::viewPrintedHeapTable() {
	system("CLS");
	cout << "-- Aktualna zawartosc kopca w postaci tablicowej: --" << endl << endl;

	if (testHeap == nullptr)
		testHeap = new Heap();

	cout << testHeap->toStringTable();

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}

void CLInterface::viewAddElementToHeap() {
	system("CLS");
	type element;

	cout << "-- Dodaj element do kopca: --" << endl << endl;
	cout << " > Wprowadz element (liczba calkowita): ";
	cin >> element;

	if (testHeap == nullptr)
		testHeap = new Heap();

	testHeap->addElement(element);

	cout << " > Element " << element << " dodany do kopca";

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}

void CLInterface::viewDeleteElementFromHeap() {

	system("CLS");

	if (testHeap == nullptr) {
		cout << " > Kopiec nie zostal zainicjalizowany" << endl;
		handleUserInput();
		return;
	}

	char decision;

	cout << "-- Usun korzen: --" << endl << endl;
	cout << " > Potwierdzenie operacji T/N: ";
	cin >> decision;


	if (decision == 'T' || decision == 't') {
		testHeap->deleteElementFromTop();
		cout << " > Korzen zostal usuniety.";
	}
	else {
		cout << " > Operacja anulowana";
	}

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}

void CLInterface::viewFindElementInHeap() {
	system("CLS");

	if (testHeap == nullptr) {
		cout << " > Kopiec nie zostal zainicjalizowany" << endl;
		handleUserInput();
		return;
	}

	int element;

	cout << "-- Znajdz indeks pierwszego (od strony pelnej) wystapienia elementu w kopcu: --" << endl << endl;
	cout << " > Wprowadz element (liczba calkowita): ";
	cin >> element;


	int foundIndex = testHeap->findElement(element);

	if (foundIndex == -1)
		cout << " > Nie znaleziono elementu: " << element;
	else {
		cout << " > Element " << element << " wystapil na pozycji " << foundIndex;
	}

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}