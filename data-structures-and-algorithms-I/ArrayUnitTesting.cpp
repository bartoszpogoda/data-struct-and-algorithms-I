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
	myArray.addElementEnd(32);
	myArray.addElementEnd(23);
	myArray.addElementEnd(32);
	myArray.addElementEnd(32);

	if (myArray.toString().compare("[32 23 32 32]") == 0)
		return true;

	return false;
}

bool ArrayUnitTesting::shouldAddFewItemsToTheFrontOfArray() {

	Array myArray = Array();
	myArray.addElementFront(4);
	myArray.addElementFront(3);
	myArray.addElementFront(2);
	myArray.addElementFront(1);

	if (myArray.toString().compare("[1 2 3 4]") == 0)
		return true;

	return false;
}

bool ArrayUnitTesting::shouldAddElementAtSpecifiedPosition()
{
	Array myArray = Array();
	myArray.addElementAt(1, 0);
	myArray.addElementAt(3, 1);
	myArray.addElementAt(2, 1);

	if (myArray.toString().compare("[1 2 3]") == 0)
		return true;

	return false;
}

bool ArrayUnitTesting::shouldAddElementAtInCaseOfIncorrectPosition() {

	Array myArray = Array();
	myArray.addElementAt(3, 55);
	myArray.addElementAt(1, -30);
	myArray.addElementAt(2, 1);

	if (myArray.toString().compare("[1 2 3]") == 0)
		return true;

	return false;
}

bool ArrayUnitTesting::shouldDeleteItemFromArray()
{
	Array myArray = Array();
	myArray.addElementEnd(1);
	myArray.addElementEnd(2);
	myArray.addElementEnd(3);
	myArray.addElementEnd(4);

	myArray.deleteElementAt(1);

	if (myArray.toString().compare("[1 3 4]") == 0)
		return true;

	return false;
}

bool ArrayUnitTesting::shouldDeleteFirstItemFromArray()
{
	Array myArray = Array();
	myArray.addElementEnd(1);
	myArray.addElementEnd(2);
	myArray.addElementEnd(3);
	myArray.addElementEnd(4);

	myArray.deleteElementFront();

	if (myArray.toString().compare("[2 3 4]") == 0)
		return true;

	return false;
}

bool ArrayUnitTesting::shouldDeleteLastItemFromArray()
{
	Array myArray = Array();
	myArray.addElementEnd(1);
	myArray.addElementEnd(2);
	myArray.addElementEnd(3);
	myArray.addElementEnd(4);

	myArray.deleteElementEnd();

	if (myArray.toString().compare("[1 2 3]") == 0)
		return true;

	return false;
}

bool ArrayUnitTesting::shouldDeleteFewItemsFromArray()
{
	Array myArray = Array();
	myArray.addElementEnd(1);
	myArray.addElementEnd(2);
	myArray.addElementEnd(3);
	myArray.addElementEnd(4);
	myArray.addElementEnd(5);

	myArray.deleteElementAt(1);
	myArray.deleteElementAt(1);
	myArray.deleteElementAt(2);

	if (myArray.toString().compare("[1 4]") == 0)
		return true;

	return false;
}

bool ArrayUnitTesting::shouldFindElement() {
	Array myArray = Array();
	myArray.addElementEnd(1);
	myArray.addElementEnd(2);
	myArray.addElementEnd(3);
	myArray.addElementEnd(4);
	myArray.addElementEnd(5);

	int position = myArray.findElement(3);

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