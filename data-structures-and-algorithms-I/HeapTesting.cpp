#include "HeapTesting.h"

void HeapTesting::runTests() {
	std::cout << "\nRunning tests for Heap: \n";
	std::cout << "shouldAddElement1: " << shouldAddElement1() << std::endl;
	std::cout << "shouldAddElement2: " << shouldAddElement2() << std::endl;
	std::cout << "shouldAddElement3: " << shouldAddElement3() << std::endl;

	std::cout << "shouldDeleteElementFromTop: " << shouldDeleteElementFromTop() << std::endl;

	std::cout << "shouldPrintEmptyHeapString: " << shouldPrintEmptyHeapString() << std::endl;

	std::cout << std::endl;
}

bool HeapTesting::shouldAddElement1() {
	//given
	Heap myHeap = Heap();

	//when
	myHeap.addElement(3);
	myHeap.addElement(2);
	myHeap.addElement(1);
	myHeap.addElement(4);

	//then
	if (myHeap.toStringTable().compare("[4 3 1 2]") == 0)
		return true;

	return false;
}

bool HeapTesting::shouldAddElement2()
{
	//given
	Heap myHeap = Heap();

	//when
	myHeap.addElement(3);
	myHeap.addElement(2);
	myHeap.addElement(1);
	myHeap.addElement(4);
	myHeap.addElement(6);
	myHeap.addElement(8);

	//then
	if (myHeap.toStringTable().compare("[8 4 6 2 3 1]") == 0)
		return true;

	return false;
}

bool HeapTesting::shouldAddElement3()
{
	return false;
}

bool HeapTesting::shouldDeleteElementFromTop()
{
	//given
	Heap myHeap = Heap();
	myHeap.addElement(3);
	myHeap.addElement(2);
	myHeap.addElement(1);
	myHeap.addElement(4);

	//when
	myHeap.deleteElementFromTop();

	//then
	if (myHeap.toStringTable().compare("[3 2 1]") == 0)
		return true;

	return false;
}

bool HeapTesting::shouldFindElement()
{
	return false;
}

bool HeapTesting::shouldPrintEmptyHeapString()
{
	//given
	Heap myHeap = Heap();
	// then
	if (myHeap.toStringTable().compare("[empty]") == 0)
		return true;

	return false;
}
