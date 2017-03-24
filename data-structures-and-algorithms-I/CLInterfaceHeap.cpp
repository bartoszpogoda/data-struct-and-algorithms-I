#include "CLInterface.h"
#include <sstream> 

using namespace std;

Heap* CLInterface::testHeap = nullptr;

void CLInterface::viewMenuHeap() {
	int selected = 0, max = 5, selectedDelta = 0;

	system("CLS");
	while (selected != max) {
		do {
			if (selected + selectedDelta >= 0 && selected + selectedDelta <= max) selected += selectedDelta;

			system("CLS");
			cout << "-- Kopiec: --" << endl << endl;
			cout << ((selected == 0) ? " > " : "   ") << "Wczytaj z pliku" << endl;
			cout << ((selected == 1) ? " > " : "   ") << "Wypisz kopiec na ekran" << endl;
			cout << ((selected == 2) ? " > " : "   ") << "Dodaj element" << endl;
			cout << ((selected == 3) ? " > " : "   ") << "Usun element ze szczytu" << endl;
			cout << ((selected == 4) ? " > " : "   ") << "Znajdz element" << endl;
			cout << ((selected == 5) ? " > " : "   ") << "Wyjscie" << endl;
		} while ((selectedDelta = handleUserInput()) != 0);

		if (selected == 0) {
			viewInputFilenameHeap();
		}
		else if (selected == 1) {
			viewPrintedHeap();
		}
		else if (selected == 2) {
			viewAddElementToHeap();
			viewPrintedHeap();
		}
		else if (selected == 3) {
			viewDeleteElementFromHeap();
			viewPrintedHeap();
		}
		else if (selected == 4) {
			viewFindElementInHeap();
			viewPrintedHeap();
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

	cout << " > Element " << element << " dodany do kopca" << endl;

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
		cout << " > Korzen zostal usuniety." << endl;
	}
	else {
		cout << " > Operacja anulowana" << endl;
	}

	handleUserInput();
}

void CLInterface::viewFindElementInHeap() {

}