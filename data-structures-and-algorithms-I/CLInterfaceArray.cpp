#include "CLInterface.h"
#include <sstream> 

using namespace std;

Array* CLInterface::testArray = nullptr;

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