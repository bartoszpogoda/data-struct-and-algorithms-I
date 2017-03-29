#include "CLInterface.h"

using namespace std;

BRTree* CLInterface::testBRTree = nullptr;

void CLInterface::viewMenuBRTree() {
	int selected = 0, max = 4, selectedDelta = 0;

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
			cout << "-- Drzewo czerwono-czarne: --" << endl << endl;
			cout << ((selected == 0) ? " > " : "   ") << "Wczytaj z pliku" << endl;
			cout << ((selected == 1) ? " > " : "   ") << "Wypisz drzewo" << endl;
			cout << ((selected == 2) ? " > " : "   ") << "Dodaj element" << endl;
			cout << ((selected == 3) ? " > " : "   ") << "Znajdz element" << endl;
			cout << ((selected == 4) ? " > " : "   ") << "Wyjscie" << endl;
		} while ((selectedDelta = handleUserInput()) != 0);

		if (selected == 0) {
			viewInputFilenameBRTree();
			viewPrintedBRTree();
		}
		else if (selected == 1) {
			viewPrintedBRTree();
		}
		else if (selected == 2) {
			viewAddElementToBRTree();
			viewPrintedBRTree();
		}
		else if (selected == 3) {
			viewFindElementInBRTree();
			viewPrintedBRTree();
		}
	}

	delete testBRTree;
	testBRTree = nullptr;
}

void CLInterface::viewInputFilenameBRTree() {
	string filename = " ";

	system("CLS");
	cout << "-- Wczytaj z pliku: --" << endl << endl;
	cout << " > Podaj nazwe pliku: ";
	cin >> filename;

	cout << "Wynik: " << fileReader.readBRTree(filename, CLInterface::testBRTree);

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}

void CLInterface::viewPrintedBRTree() {
	system("CLS");
	cout << "-- Aktualna zawartosc drzewa czerwono-czarnego: --" << endl 
		<< " (Czarne wezly) , Czerwone wezly " << endl << endl;

	if (testBRTree == nullptr)
		testBRTree = new BRTree();

	printer.print_tree(testBRTree->getRoot());

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}

void CLInterface::viewAddElementToBRTree() {
	system("CLS");
	type element;

	cout << "-- Dodaj element do drzewa czerwono-czarnego: --" << endl << endl;
	cout << " > Wprowadz element (liczba calkowita): ";
	cin >> element;

	if (testBRTree == nullptr)
		testBRTree = new BRTree();

	testBRTree->add(element);

	cout << " > Element " << element << " dodany do drzewa czerwono-czarnego";

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}

void CLInterface::viewFindElementInBRTree() {
	system("CLS");

	if (testBRTree == nullptr) {
		cout << " > Drzewo czerwono-czarne nie zostalo zainicjalizowane" << endl;
		cout << endl << "> Powrot: Enter";
		handleUserInput();
		return;
	}

	int element;

	cout << "-- Znajdz element w drzewie czerwono-czarnym: --" << endl << endl;
	cout << " > Wprowadz element (liczba calkowita): ";
	cin >> element;


	bool found = testBRTree->find(element);

	if (found)
		cout << " > Element " << element << " zostal odnaleziony ";
	else {
		cout << " > Nie znaleziono elementu: " << element;
	}

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}
