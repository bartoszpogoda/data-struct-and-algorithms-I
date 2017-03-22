#pragma once

#include "BDList.h"

class BDListTesting {
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

	static bool shouldFindElement();

	static bool shouldPrintEmptyListString();
};