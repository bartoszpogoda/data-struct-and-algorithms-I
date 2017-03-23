#pragma once

#include "Heap.h"

class HeapTesting {
public:
	static void runTests();

	static bool shouldAddElement1();
	static bool shouldAddElement2();
	static bool shouldAddElement3();

	static bool shouldDeleteElementFromTop();

	static bool shouldFindElement();

	static bool shouldPrintEmptyHeapString();
};