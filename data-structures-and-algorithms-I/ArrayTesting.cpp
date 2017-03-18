#include "ArrayTesting.h"

void ArrayTesting::runTests() {
	std::cout << "Running tests: \n";
	std::cout << "shouldAddFewItemsToArray: " << shouldAddFewItemsToArray() << std::endl;
	std::cout << "shouldAddFewItemsToTheFrontOfArray: " << shouldAddFewItemsToTheFrontOfArray() << std::endl;
	std::cout << "shouldAddElementAtSpecifiedPosition: " << shouldAddElementAtSpecifiedPosition() << std::endl;
	std::cout << "shouldAddElementAtInCaseOfIncorrectPosition: " << shouldAddElementAtInCaseOfIncorrectPosition() << std::endl;
	std::cout << "shouldPrintEmptyArrayString: " << shouldPrintEmptyArrayString() << std::endl;
}

bool ArrayTesting::shouldAddFewItemsToArray() {

	Array myArray = Array();
	myArray.addElement(32);
	myArray.addElement(23);
	myArray.addElement(32);
	myArray.addElement(32);

	if (myArray.toString().compare("[32 23 32 32]") == 0)
		return true;

	return false;
}

bool ArrayTesting::shouldAddFewItemsToTheFrontOfArray() {

	Array myArray = Array();
	myArray.addElementFront(4);
	myArray.addElementFront(3);
	myArray.addElementFront(2);
	myArray.addElementFront(1);

	if (myArray.toString().compare("[1 2 3 4]") == 0)
		return true;

	return false;
}

bool ArrayTesting::shouldAddElementAtSpecifiedPosition()
{
	Array myArray = Array();
	myArray.addElementAt(1, 0);
	myArray.addElementAt(3, 1);
	myArray.addElementAt(2, 1);

	if (myArray.toString().compare("[1 2 3]") == 0)
		return true;

	return false;
}

bool ArrayTesting::shouldAddElementAtInCaseOfIncorrectPosition() {

	Array myArray = Array();
	myArray.addElementAt(3, 55);
	myArray.addElementAt(1, -30);
	myArray.addElementAt(2, 1);

	if (myArray.toString().compare("[1 2 3]") == 0)
		return true;

	return false;
}

bool ArrayTesting::shouldPrintEmptyArrayString() {

	Array myArray = Array();

	if (myArray.toString().compare("[empty]") == 0)
		return true;

	return false;
}