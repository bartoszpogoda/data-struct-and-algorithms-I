#include "CLInterface.h"

using namespace std;

BSTree* CLInterface::testBSTree = nullptr;

void CLInterface::viewMenuBSTree() {
	int selected = 0, max = 8, selectedDelta = 0;

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
			cout << "-- Drzewo BST: --" << endl << endl;
			cout << ((selected == 0) ? " > " : "   ") << "Wczytaj z pliku" << endl;
			cout << ((selected == 1) ? " > " : "   ") << "Wypisz drzewo" << endl;
			cout << ((selected == 2) ? " > " : "   ") << "Dodaj element" << endl;
			cout << ((selected == 3) ? " > " : "   ") << "Usun element" << endl;
			cout << ((selected == 4) ? " > " : "   ") << "Znajdz element" << endl;
			cout << "   " << "Rotacje:" << endl; 
			cout << ((selected == 5) ? "    > " : "      ") << "Lewo" << endl;
			cout << ((selected == 6) ? "    > " : "      ") << "Prawo" << endl;
			cout << ((selected == 7) ? " > " : "   ") << "Rownowazenie DSW" << endl << endl;
			cout << ((selected == 8) ? " > " : "   ") << "Wyjscie" << endl;
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
			viewDeleteElementFromBSTree();
			viewPrintedBSTree();
		}
		else if (selected == 4) {
			viewFindElementInBSTree();
			viewPrintedBSTree();
		}
		else if (selected == 5) {
			viewRotateLeftBSTree();
			viewPrintedBSTree();
		}
		else if (selected == 6) {
			viewRotateRightBSTree();
			viewPrintedBSTree();
		}
		else if (selected == 7) {
			viewPerformDSWBSTree();
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
	cout << "-- Aktualna zawartosc drzewa BST: --" << endl << endl;

	if (testBSTree == nullptr) {
		testBSTree = new BSTree();
	}

	if (testBSTree->isEmpty())
		cout << "> Drzewo BST jest puste" << endl;
	else
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

void CLInterface::viewDeleteElementFromBSTree() {
	system("CLS");

	if (testBSTree == nullptr || testBSTree->isEmpty()) {
		return;
	}
	
	int element;

	cout << "-- Usun element z drzewa BST: --" << endl << endl;
	cout << " > Wprowadz element (liczba calkowita): ";
	cin >> element;


	bool deleted = testBSTree->remove(element);

	if (deleted)
		cout << " > Element " << element << " zostal usuniety ";
	else {
		cout << " > Nie znaleziono elementu: " << element;
	}

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}

void CLInterface::viewFindElementInBSTree() {
	system("CLS");

	if (testBSTree == nullptr || testBSTree->isEmpty()) {
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

void CLInterface::viewRotateLeftBSTree() {
	system("CLS");

	if (testBSTree == nullptr || testBSTree->isEmpty()) {
		return;
	}

	int element;

	cout << "-- Rotacja w lewo dla drzewa BST: --" << endl << endl;
	cout << " > Wprowadz element (liczba calkowita): ";
	cin >> element;


	bool rotated = testBSTree->rotateLeftAt(element);

	if (rotated)
		cout << " > Rotacja na elemencie " << element << " zostala wykonana ";
	else {
		cout << " > Nie znaleziono elementu: " << element;
	}

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}

void CLInterface::viewRotateRightBSTree() {
	system("CLS");

	if (testBSTree == nullptr || testBSTree->isEmpty()) {
		return;
	}

	int element;

	cout << "-- Rotacja w prawo dla drzewa BST: --" << endl << endl;
	cout << " > Wprowadz element (liczba calkowita): ";
	cin >> element;


	bool rotated = testBSTree->rotateRightAt(element);

	if (rotated)
		cout << " > Rotacja na elemencie " << element << " zostala wykonana ";
	else {
		cout << " > Nie znaleziono elementu: " << element;
	}

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}

void CLInterface::viewPerformDSWBSTree() {
	system("CLS");

	if (testBSTree == nullptr || testBSTree->isEmpty()) {
		return;
	}
	
	cout << "-- Wykonaj rownowazenie DSW na drzewie BST: --" << endl << endl;

	char decision;
	cout << " > Potwierdzenie operacji T/N: ";
	cin >> decision;

	if (decision == 'T' || decision == 't') {
		testBSTree->performDSW();
		cout << " > Rownowazenie zostalo wykonane.";
	}
	else {
		cout << " > Operacja anulowana";
	}

	cout << endl << endl << "> Powrot: Enter";
	handleUserInput();
}
