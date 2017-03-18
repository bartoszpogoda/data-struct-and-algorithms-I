#include "TestingComp.h"

void TestingComp::runTests() {

	std::cout << "Running tests: \n";
	std::cout << "shouldAddFewItemsToArray: " << shouldAddFewItemsToArray() << std::endl;
	std::cout << "shouldPrintEmptyArrayString: " << shouldPrintEmptyArrayString() << std::endl;
}

bool TestingComp::shouldAddFewItemsToArray() {

	Array myArray = Array();
	myArray.addElement(32);
	myArray.addElement(23);
	myArray.addElement(32);
	myArray.addElement(32);

	if (myArray.toString().compare("[32 23 32 32]") == 0)
		return true;

	return false;
}

bool TestingComp::shouldPrintEmptyArrayString() {

	Array myArray = Array();

	if (myArray.toString().compare("[empty]") == 0)
		return true;

	return false;
}