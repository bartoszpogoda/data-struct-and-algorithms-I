#pragma once

#include "Array.h"
#include "Printable.h"

class TestingComp {
public:
	void runTests();

	bool shouldAddFewItemsToArray();
	bool shouldPrintEmptyArrayString();
};