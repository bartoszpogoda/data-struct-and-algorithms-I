#pragma once

#include "Heap.h"

class HeapUnitTesting {
public:
	static void runTests();

	static bool shouldAddElement1();
	static bool shouldAddElement2();
	static bool shouldAddElement3();

	static bool shouldDeleteElementFromTop1();
	static bool shouldDeleteElementFromTop2();

	static bool shouldFindElement();

	static bool shouldPrintEmptyHeapString();
};