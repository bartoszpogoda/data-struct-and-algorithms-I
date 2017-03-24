#include "HeapUnitTesting.h"

void HeapUnitTesting::runTests() {
	std::cout << "\nRunning tests for Heap: \n";
	std::cout << "shouldAddElement1: " << shouldAddElement1() << std::endl;
	std::cout << "shouldAddElement2: " << shouldAddElement2() << std::endl;
	std::cout << "shouldAddElement3: " << shouldAddElement3() << std::endl;

	std::cout << "shouldDeleteElementFromTop1: " << shouldDeleteElementFromTop1() << std::endl;
	std::cout << "shouldDeleteElementFromTop2: " << shouldDeleteElementFromTop2() << std::endl;

	std::cout << "shouldFindElement: " << shouldFindElement() << std::endl;

	std::cout << "shouldPrintEmptyHeapString: " << shouldPrintEmptyHeapString() << std::endl;

	std::cout << std::endl;
}

bool HeapUnitTesting::shouldAddElement1() {
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

bool HeapUnitTesting::shouldAddElement2() {
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

bool HeapUnitTesting::shouldAddElement3() {
	//given
	Heap myHeap = Heap();

	//when
	myHeap.addElement(1);
	myHeap.addElement(1);
	myHeap.addElement(1);
	myHeap.addElement(1);
	myHeap.addElement(1);
	myHeap.addElement(5);

	//then
	if (myHeap.toStringTable().compare("[5 1 1 1 1 1]") == 0)
		return true;

	return false;
}

bool HeapUnitTesting::shouldDeleteElementFromTop1() {
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

bool HeapUnitTesting::shouldDeleteElementFromTop2() {
	//given
	Heap myHeap = Heap();
	myHeap.addElement(3);
	myHeap.addElement(2);
	myHeap.addElement(1);
	myHeap.addElement(4);
	myHeap.addElement(6);
	myHeap.addElement(8);

	//when
	myHeap.deleteElementFromTop();

	//then
	if (myHeap.toStringTable().compare("[6 4 1 2 3]") == 0)
		return true;

	return false;
}

bool HeapUnitTesting::shouldFindElement() {
	//given "[8 4 6 2 3 1]"
	Heap myHeap = Heap();
	myHeap.addElement(3);
	myHeap.addElement(2);
	myHeap.addElement(1);
	myHeap.addElement(4);
	myHeap.addElement(6);
	myHeap.addElement(8); 

	//when
	int foundId = myHeap.findElement(6);
	//then
	if (foundId == 2)
		return true;

	return false;
}

bool HeapUnitTesting::shouldPrintEmptyHeapString() {
	//given
	Heap myHeap = Heap();
	// then
	if (myHeap.toStringTable().compare("[empty]") == 0)
		return true;

	return false;
}
