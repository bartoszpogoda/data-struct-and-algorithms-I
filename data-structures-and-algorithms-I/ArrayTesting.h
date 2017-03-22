#pragma once

#include "Array.h"

class ArrayTesting {
public:
	static void runTests();

	static bool shouldAddFewItemsToArray();
	static bool shouldAddFewItemsToTheFrontOfArray();
	static bool shouldAddElementAtSpecifiedPosition();
	static bool shouldAddElementAtInCaseOfIncorrectPosition();

	static bool shouldDeleteItemFromArray();
	static bool shouldDeleteFirstItemFromArray();
	static bool shouldDeleteLastItemFromArray();
	static bool shouldDeleteFewItemsFromArray();

	static bool shouldFindElement();

	static bool shouldPrintEmptyArrayString();
};