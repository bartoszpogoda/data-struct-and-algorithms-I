#pragma once

#include "BDList.h"

class BDListUnitTesting {
public:
	static void runTests();

	static bool shouldAddFewItemsToList();
	static bool shouldAddFewItemsToTheFrontOfList();
	static bool shouldAddElementAtSpecifiedPosition();
	static bool shouldAddElementAtInCaseOfIncorrectPosition();

	static bool shouldDeleteItemFromList();
	static bool shouldDeleteFirstItemFromList();
	static bool shouldDeleteLastItemFromList();
	static bool shouldDeleteFewItemsFromList();
	static bool shouldDeleteItemFromListIndex0();
	static bool shouldDeleteItemFromListIndex0SingleElement();
	static bool shouldDeleteItemFromListIndexLast();

	static bool shouldFindElement();
	static bool shouldGetElement();

	static bool shouldPrintEmptyListString();
};