#include "BDListUnitTesting.h"
#include "Type.h"

void BDListUnitTesting::runTests() {

	std::cout << "\nRunning tests for BDList: \n";
	std::cout << "shouldAddFewItemsToList: " << shouldAddFewItemsToList() << std::endl;
	std::cout << "shouldAddFewItemsToTheFrontOfList: " << shouldAddFewItemsToTheFrontOfList() << std::endl;
	std::cout << "shouldAddElementAtSpecifiedPosition: " << shouldAddElementAtSpecifiedPosition() << std::endl;
	std::cout << "shouldAddElementAtInCaseOfIncorrectPosition: " << shouldAddElementAtInCaseOfIncorrectPosition() << std::endl;
	

	std::cout << "shouldDeleteItemFromList: " << shouldDeleteItemFromList() << std::endl;
	std::cout << "shouldDeleteItemFromListIndex0: " << shouldDeleteItemFromListIndex0() << std::endl;
	std::cout << "shouldDeleteItemFromListIndex0SingleElement: " << shouldDeleteItemFromListIndex0SingleElement() << std::endl;
	std::cout << "shouldDeleteItemFromListIndexLast: " << shouldDeleteItemFromListIndexLast() << std::endl;
	std::cout << "shouldDeleteFirstItemFromList: " << shouldDeleteFirstItemFromList() << std::endl;
	std::cout << "shouldDeleteLastItemFromList: " << shouldDeleteLastItemFromList() << std::endl;
	std::cout << "shouldDeleteFewItemsFromList: " << shouldDeleteFewItemsFromList() << std::endl;

	std::cout << "shouldFindElement: " << shouldFindElement() << std::endl;
	std::cout << "shouldGetElement: " << shouldGetElement() << std::endl;
	
	std::cout << "shouldPrintEmptyListString: " << shouldPrintEmptyListString() << std::endl;

	std::cout << std::endl;
}

bool BDListUnitTesting::shouldAddFewItemsToList() {
	//given
	BDList myBDList = BDList();

	//when
	myBDList.addEnd(32);
	myBDList.addEnd(23);
	myBDList.addEnd(32);
	myBDList.addEnd(32);

	//then
	if (myBDList.toString().compare("[32 <-> 23 <-> 32 <-> 32]") == 0)
		return true;

	return false;
}

bool BDListUnitTesting::shouldAddFewItemsToTheFrontOfList() {
	//given
	BDList myBDList = BDList();

	//when
	myBDList.addFront(4);
	myBDList.addFront(3);
	myBDList.addFront(2);
	myBDList.addFront(1);

	//then
	if (myBDList.toString().compare("[1 <-> 2 <-> 3 <-> 4]") == 0)
		return true;

	return false;
}

bool BDListUnitTesting::shouldAddElementAtSpecifiedPosition() {
	//given
	BDList myBDList = BDList();

	//when
	myBDList.addAt(3, 0);
	myBDList.addAt(2, 0);
	myBDList.addAt(1, 0);
	myBDList.addAt(5, 1);

	//then
	if (myBDList.toString().compare("[1 <-> 5 <-> 2 <-> 3]") == 0)
		return true;

	return false;
}

bool BDListUnitTesting::shouldAddElementAtInCaseOfIncorrectPosition() {
	//given
	BDList myBDList = BDList();

	//when
	myBDList.addAt(3, 55);
	myBDList.addAt(1, -30);
	myBDList.addAt(2, 1);
	
	//then
	if (myBDList.toString().compare("[1 <-> 2 <-> 3]") == 0)
		return true;

	return false;
}

bool BDListUnitTesting::shouldDeleteItemFromList() {
	//given
	BDList myBDList = BDList();
	myBDList.addEnd(1);
	myBDList.addEnd(2);
	myBDList.addEnd(3);
	myBDList.addEnd(4);

	//when
	myBDList.deleteAt(1);

	//then
	if (myBDList.toString().compare("[1 <-> 3 <-> 4]") == 0)
		return true;

	return false;
}

bool BDListUnitTesting::shouldDeleteItemFromListIndex0() {
	//given
	BDList myBDList = BDList();
	myBDList.addEnd(1);
	myBDList.addEnd(2);
	myBDList.addEnd(3);
	myBDList.addEnd(4);

	//when
	myBDList.deleteAt(0);

	//then
	if (myBDList.toString().compare("[2 <-> 3 <-> 4]") == 0)
		return true;

	return false;
}

bool BDListUnitTesting::shouldDeleteItemFromListIndex0SingleElement() {
	//given
	BDList myBDList = BDList();
	myBDList.addEnd(1);

	//when
	myBDList.deleteAt(0);

	//then
	if (myBDList.toString().compare("[empty]") == 0)
		return true;

	return false;
}

bool BDListUnitTesting::shouldDeleteItemFromListIndexLast() {
	//given
	BDList myBDList = BDList();
	myBDList.addEnd(1);
	myBDList.addEnd(2);
	myBDList.addEnd(3);
	myBDList.addEnd(4);

	//when
	myBDList.deleteAt(3);

	//then
	if (myBDList.toString().compare("[1 <-> 2 <-> 3]") == 0)
		return true;

	return false;
}

bool BDListUnitTesting::shouldDeleteFirstItemFromList() {
	//given
	BDList myBDList = BDList();
	myBDList.addEnd(1);
	myBDList.addEnd(2);
	myBDList.addEnd(3);
	myBDList.addEnd(4);

	//when
	myBDList.deleteFront();

	//then
	if (myBDList.toString().compare("[2 <-> 3 <-> 4]") == 0)
		return true;

	return false;
}

bool BDListUnitTesting::shouldDeleteLastItemFromList() {
	//given
	BDList myBDList = BDList();
	myBDList.addEnd(1);
	myBDList.addEnd(2);
	myBDList.addEnd(3);
	myBDList.addEnd(4);

	//when
	myBDList.deleteEnd();

	//then
	if (myBDList.toString().compare("[1 <-> 2 <-> 3]") == 0)
		return true;

	return false;;
}

bool BDListUnitTesting::shouldDeleteFewItemsFromList() {
	//given
	BDList myBDList = BDList();
	myBDList.addEnd(1);
	myBDList.addEnd(2);
	myBDList.addEnd(3);
	myBDList.addEnd(4);
	myBDList.addEnd(5);

	//when
	myBDList.deleteAt(1);
	myBDList.deleteAt(1);
	myBDList.deleteAt(2);

	//then
	if (myBDList.toString().compare("[1 <-> 4]") == 0)
		return true;

	return false;
}

bool BDListUnitTesting::shouldFindElement() {
	//given
	BDList myBDList = BDList();
	myBDList.addEnd(1);
	myBDList.addEnd(2);
	myBDList.addEnd(3);
	myBDList.addEnd(4);
	myBDList.addEnd(5);
	
	//when
	int position = myBDList.find(3);

	//then
	if (position == 2)
		return true;

	return false;
}

bool BDListUnitTesting::shouldGetElement() {
	//given
	BDList myBDList = BDList();
	myBDList.addEnd(1);
	myBDList.addEnd(2);
	myBDList.addEnd(3);
	myBDList.addEnd(4);
	myBDList.addEnd(5);

	//when
	type element = myBDList.get(2);

	//then
	if (element == 3)
		return true;

	return false;
}

bool BDListUnitTesting::shouldPrintEmptyListString() {
	//given
	BDList myBDList = BDList();
	// then
	if (myBDList.toString().compare("[empty]") == 0)
		return true;

	return false;
}
