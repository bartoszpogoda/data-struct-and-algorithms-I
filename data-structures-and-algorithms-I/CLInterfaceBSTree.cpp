#include "CLInterface.h"

using namespace std;

BSTree* CLInterface::testBSTree = nullptr;

void CLInterface::viewMenuBSTree() {
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
			viewInputFilenameBSTree();
			viewPrintedBSTree();
		}
		else if (selected == 1) {
			viewPrintedBSTree();
		}
		else if (selected == 2) {
			viewAddElementToBSTree();
			viewPrintedBSTree();
		}
		else if (selected == 3) {
			viewFindElementInBSTree();
			viewPrintedBSTree();
		}
	}

	delete testBSTree;
	testBSTree = nullptr;
}

void CLInterface::viewInputFilenameBSTree() {
	string filename = " ";

	system("CLS");
	cout << "-- Wczytaj z pliku: --" << endl << endl;
	cout << " > Podaj nazwe pliku: ";
	cin >> filename;

	cout << "Wynik: " << fileReader.readBSTree(filename, CLInterface::testBSTree);

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}

void CLInterface::viewPrintedBSTree() {
	system("CLS");
	cout << "-- Aktualna zawartosc drzewa czerwono-czarnego: --" << endl;

	if (testBSTree == nullptr)
		testBSTree = new BSTree();

	printer.print_tree("","",testBSTree->getRoot());

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}

void CLInterface::viewAddElementToBSTree() {
	system("CLS");
	type element;

	cout << "-- Dodaj element do drzewa czerwono-czarnego: --" << endl << endl;
	cout << " > Wprowadz element (liczba calkowita): ";
	cin >> element;

	if (testBSTree == nullptr)
		testBSTree = new BSTree();

	testBSTree->add(element);

	cout << " > Element " << element << " dodany do drzewa czerwono-czarnego";

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}

void CLInterface::viewFindElementInBSTree() {
	system("CLS");

	if (testBSTree == nullptr) {
		cout << " > Drzewo czerwono-czarne nie zostalo zainicjalizowane" << endl;
		cout << endl << "> Powrot: Enter";
		handleUserInput();
		return;
	}

	int element;

	cout << "-- Znajdz element w drzewie czerwono-czarnym: --" << endl << endl;
	cout << " > Wprowadz element (liczba calkowita): ";
	cin >> element;


	bool found = testBSTree->find(element);

	if (found)
		cout << " > Element " << element << " zostal odnaleziony ";
	else {
		cout << " > Nie znaleziono elementu: " << element;
	}

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}
