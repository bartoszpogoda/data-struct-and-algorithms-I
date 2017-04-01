#pragma once
#include "Type.h"
#include <string>

class Heap {

private:
	type* elements;
	int currentSize;

	void fixUp(int nodeId);
	void fixDown(int nodeId);
public:
	Heap() : elements(nullptr), currentSize(0) { };
	~Heap();

	int size() { return currentSize; }

	void add(type element);
	void deleteRoot();

	int find(type element);

	int parent(int nodeId) { return (nodeId - 1) / 2; }
	int leftChild(int nodeId) { return 2 * nodeId + 1; }
	int rightChild(int nodeId) { return 2 * nodeId + 2; }

	int get(int position) { return elements[position]; }

	bool validate(int node);

	std::string toStringTable();
};