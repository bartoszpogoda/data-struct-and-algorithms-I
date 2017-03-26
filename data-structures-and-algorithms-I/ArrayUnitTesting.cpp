#include "ArrayUnitTesting.h"
#include "Type.h"

void ArrayUnitTesting::runTests() {
	std::cout << "\nRunning tests for Array: \n";
	std::cout << "shouldAddFewItemsToArray: " << shouldAddFewItemsToArray() << std::endl;
	std::cout << "shouldAddFewItemsToTheFrontOfArray: " << shouldAddFewItemsToTheFrontOfArray() << std::endl;
	std::cout << "shouldAddElementAtSpecifiedPosition: " << shouldAddElementAtSpecifiedPosition() << std::endl;
	std::cout << "shouldAddElementAtInCaseOfIncorrectPosition: " << shouldAddElementAtInCaseOfIncorrectPosition() << std::endl;


	std::cout << "shouldDeleteItemFromArray: " << shouldDeleteItemFromArray() << std::endl;
	std::cout << "shouldDeleteFirstItemFromArray: " << shouldDeleteFirstItemFromArray() << std::endl;
	std::cout << "shouldDeleteLastItemFromArray: " << shouldDeleteLastItemFromArray() << std::endl;
	std::cout << "shouldDeleteFewItemsFromArray: " << shouldDeleteFewItemsFromArray() << std::endl;

	std::cout << "shouldFindElement: " << shouldFindElement() << std::endl;

	std::cout << "shouldPrintEmptyArrayString: " << shouldPrintEmptyArrayString() << std::endl;

	std::cout << std::endl;
}

bool ArrayUnitTesting::shouldAddFewItemsToArray() {

	Array myArray = Array();
	myArray.addEnd(32);
	myArray.addEnd(23);
	myArray.addEnd(32);
	myArray.addEnd(32);

	if (myArray.toString().compare("[32 23 32 32]") == 0)
		return true;

	return false;
}

bool ArrayUnitTesting::shouldAddFewItemsToTheFrontOfArray() {

	Array myArray = Array();
	myArray.addFront(4);
	myArray.addFront(3);
	myArray.addFront(2);
	myArray.addFront(1);

	if (myArray.toString().compare("[1 2 3 4]") == 0)
		return true;

	return false;
}

bool ArrayUnitTesting::shouldAddElementAtSpecifiedPosition()
{
	Array myArray = Array();
	myArray.addAt(1, 0);
	myArray.addAt(3, 1);
	myArray.addAt(2, 1);

	if (myArray.toString().compare("[1 2 3]") == 0)
		return true;

	return false;
}

bool ArrayUnitTesting::shouldAddElementAtInCaseOfIncorrectPosition() {

	Array myArray = Array();
	myArray.addAt(3, 55);
	myArray.addAt(1, -30);
	myArray.addAt(2, 1);

	if (myArray.toString().compare("[1 2 3]") == 0)
		return true;

	return false;
}

bool ArrayUnitTesting::shouldDeleteItemFromArray()
{
	Array myArray = Array();
	myArray.addEnd(1);
	myArray.addEnd(2);
	myArray.addEnd(3);
	myArray.addEnd(4);

	myArray.deleteAt(1);

	if (myArray.toString().compare("[1 3 4]") == 0)
		return true;

	return false;
}

bool ArrayUnitTesting::shouldDeleteFirstItemFromArray()
{
	Array myArray = Array();
	myArray.addEnd(1);
	myArray.addEnd(2);
	myArray.addEnd(3);
	myArray.addEnd(4);

	myArray.deleteFront();

	if (myArray.toString().compare("[2 3 4]") == 0)
		return true;

	return false;
}

bool ArrayUnitTesting::shouldDeleteLastItemFromArray()
{
	Array myArray = Array();
	myArray.addEnd(1);
	myArray.addEnd(2);
	myArray.addEnd(3);
	myArray.addEnd(4);

	myArray.deleteEnd();

	if (myArray.toString().compare("[1 2 3]") == 0)
		return true;

	return false;
}

bool ArrayUnitTesting::shouldDeleteFewItemsFromArray()
{
	Array myArray = Array();
	myArray.addEnd(1);
	myArray.addEnd(2);
	myArray.addEnd(3);
	myArray.addEnd(4);
	myArray.addEnd(5);

	myArray.deleteAt(1);
	myArray.deleteAt(1);
	myArray.deleteAt(2);

	if (myArray.toString().compare("[1 4]") == 0)
		return true;

	return false;
}

bool ArrayUnitTesting::shouldFindElement() {
	Array myArray = Array();
	myArray.addEnd(1);
	myArray.addEnd(2);
	myArray.addEnd(3);
	myArray.addEnd(4);
	myArray.addEnd(5);

	int position = myArray.find(3);

	if (position == 2)
		return true;

	return false;
}

bool ArrayUnitTesting::shouldPrintEmptyArrayString() {

	Array myArray = Array();

	if (myArray.toString().compare("[empty]") == 0)
		return true;

	return false;
}