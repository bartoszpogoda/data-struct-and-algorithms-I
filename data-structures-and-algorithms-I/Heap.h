#pragma once
#include "Type.h"
#include <iostream>
#include <vector>

class Heap {

private:
	type* elements;
	int currentSize;

	void fixUp(int nodeId);
	void fixDown(int nodeId);

	int parent(int nodeId) { return (nodeId - 1)/2; }
	int leftChild(int nodeId) { return 2 * nodeId + 1; }
	int rightChild(int nodeId) { return 2 * nodeId + 2; }

public:
	Heap() : elements(nullptr), currentSize(0) { };
	~Heap();

	int size() { return currentSize; }

	void addElement(type element);
	void deleteElementFromTop();

	int findElement(type element);

	std::string toStringTable();
	std::vector<type> getVector();
};