#include "BDListTesting.h"

void BDListTesting::runTests() {

	std::cout << "Running tests for BDList: \n";
	std::cout << "shouldAddFewItemsToList: " << shouldAddFewItemsToList() << std::endl;
	std::cout << "shouldAddFewItemsToTheFrontOfList: " << shouldAddFewItemsToTheFrontOfList() << std::endl;
	std::cout << "shouldAddElementAtSpecifiedPosition: " << shouldAddElementAtSpecifiedPosition() << std::endl;
	std::cout << "shouldAddElementAtInCaseOfIncorrectPosition: " << shouldAddElementAtInCaseOfIncorrectPosition() << std::endl;


	std::cout << "shouldDeleteItemFromList: " << shouldDeleteItemFromList() << std::endl;
	std::cout << "shouldDeleteFirstItemFromList: " << shouldDeleteFirstItemFromList() << std::endl;
	std::cout << "shouldDeleteLastItemFromList: " << shouldDeleteLastItemFromList() << std::endl;
	std::cout << "shouldDeleteFewItemsFromList: " << shouldDeleteFewItemsFromList() << std::endl;

	std::cout << "shouldFindElement: " << shouldFindElement() << std::endl;

	std::cout << "shouldPrintEmptyListString: " << shouldPrintEmptyListString() << std::endl;
}

bool BDListTesting::shouldAddFewItemsToList() {
	//given
	BDList myBDList = BDList();

	//when
	myBDList.addElementEnd(32);
	myBDList.addElementEnd(23);
	myBDList.addElementEnd(32);
	myBDList.addElementEnd(32);

	//then
	if (myBDList.toString().compare("[32 <-> 23 <-> 32 <-> 32]") == 0)
		return true;

	return false;
}

bool BDListTesting::shouldAddFewItemsToTheFrontOfList() {
	//given
	BDList myBDList = BDList();

	//when
	myBDList.addElementFront(4);
	myBDList.addElementFront(3);
	myBDList.addElementFront(2);
	myBDList.addElementFront(1);

	//then
	if (myBDList.toString().compare("[1 <-> 2 <-> 3 <-> 4]") == 0)
		return true;

	return false;
}

bool BDListTesting::shouldAddElementAtSpecifiedPosition() {
	//given
	BDList myBDList = BDList();

	//when
	myBDList.addElementAt(1, 0);
	myBDList.addElementAt(3, 1);
	myBDList.addElementAt(2, 1);

	//then
	if (myBDList.toString().compare("[1 <-> 2 <-> 3]") == 0)
		return true;

	return false;
}

bool BDListTesting::shouldAddElementAtInCaseOfIncorrectPosition() {
	//given
	BDList myBDList = BDList();

	//when
	myBDList.addElementAt(3, 55);
	myBDList.addElementAt(1, -30);
	myBDList.addElementAt(2, 1);

	//then
	if (myBDList.toString().compare("[1 <-> 2 <-> 3]") == 0)
		return true;

	return false;
}

bool BDListTesting::shouldDeleteItemFromList() {
	//given
	BDList myBDList = BDList();
	myBDList.addElementEnd(1);
	myBDList.addElementEnd(2);
	myBDList.addElementEnd(3);
	myBDList.addElementEnd(4);

	//when
	myBDList.deleteElementAt(1);

	//then
	if (myBDList.toString().compare("[1 <-> 3 <-> 4]") == 0)
		return true;

	return false;
}

bool BDListTesting::shouldDeleteFirstItemFromList() {
	//given
	BDList myBDList = BDList();
	myBDList.addElementEnd(1);
	myBDList.addElementEnd(2);
	myBDList.addElementEnd(3);
	myBDList.addElementEnd(4);

	//when
	myBDList.deleteElementFront();

	//then
	if (myBDList.toString().compare("[2 <-> 3 <-> 4]") == 0)
		return true;

	return false;
}

bool BDListTesting::shouldDeleteLastItemFromList() {
	//given
	BDList myBDList = BDList();
	myBDList.addElementEnd(1);
	myBDList.addElementEnd(2);
	myBDList.addElementEnd(3);
	myBDList.addElementEnd(4);

	//when
	myBDList.deleteElementEnd();

	//then
	if (myBDList.toString().compare("[1 <-> 2 <-> 3]") == 0)
		return true;

	return false;;
}

bool BDListTesting::shouldDeleteFewItemsFromList() {
	//given
	BDList myBDList = BDList();
	myBDList.addElementEnd(1);
	myBDList.addElementEnd(2);
	myBDList.addElementEnd(3);
	myBDList.addElementEnd(4);
	myBDList.addElementEnd(5);

	//when
	myBDList.deleteElementAt(1);
	myBDList.deleteElementAt(1);
	myBDList.deleteElementAt(2);

	//then
	if (myBDList.toString().compare("[1 <-> 4]") == 0)
		return true;

	return false;
}

bool BDListTesting::shouldFindElement() {
	//given
	BDList myBDList = BDList();
	myBDList.addElementEnd(1);
	myBDList.addElementEnd(2);
	myBDList.addElementEnd(3);
	myBDList.addElementEnd(4);
	myBDList.addElementEnd(5);
	
	//when
	int position = myBDList.findElement(3);

	//then
	if (position == 2)
		return true;

	return false;
}

bool BDListTesting::shouldPrintEmptyListString() {
	//given
	BDList myBDList = BDList();
	// then
	if (myBDList.toString().compare("[empty]") == 0)
		return true;

	return false;
}
