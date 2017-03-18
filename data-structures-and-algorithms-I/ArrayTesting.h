#pragma once

#include "Array.h"
#include "Printable.h"

class ArrayTesting {
public:
	static void runTests();

	static bool shouldAddFewItemsToArray();
	static bool shouldAddFewItemsToTheFrontOfArray();
	static bool shouldAddElementAtSpecifiedPosition();
	static bool shouldAddElementAtInCaseOfIncorrectPosition();
	static bool shouldPrintEmptyArrayString();
};