#include "Heap.h"
#include <string>

void Heap::fixUp(int nodeId) {
	while (parent(nodeId) >= 0) {
		// if parent has less value
		if (elements[parent(nodeId)] < elements[nodeId]) {
			// swap with parent
			type dataHolder = elements[nodeId];
			elements[nodeId] = elements[parent(nodeId)];
			elements[parent(nodeId)] = dataHolder;

			// for next iteration
			nodeId = parent(nodeId);
		}
		else {
			// heap fixed
			return;
		}
	}
}

void Heap::fixDown(int nodeId) {
	while (leftChild(nodeId) < currentSize) {
		// if left child has bigger value
		if (elements[leftChild(nodeId)] > elements[nodeId]) {
			// if right child exists and has bigger value than left
			if (rightChild(nodeId) < currentSize && elements[rightChild(nodeId)] > elements[leftChild(nodeId)]) {
				// swap with right child
				type dataHolder = elements[nodeId];
				elements[nodeId] = elements[rightChild(nodeId)];
				elements[rightChild(nodeId)] = dataHolder;

				// for next iteration
				nodeId = rightChild(nodeId);
			}
			else {
				// swap with left child
				type dataHolder = elements[nodeId];
				elements[nodeId] = elements[leftChild(nodeId)];
				elements[leftChild(nodeId)] = dataHolder;

				// for next iteration
				nodeId = leftChild(nodeId);
			}

		} // if right child exists and has bigger value
		else if (rightChild(nodeId) < currentSize && elements[rightChild(nodeId)] > elements[nodeId]) {
			// swap with right child
			type dataHolder = elements[nodeId];
			elements[nodeId] = elements[rightChild(nodeId)];
			elements[rightChild(nodeId)] = dataHolder;

			// for next iteration
			nodeId = rightChild(nodeId);
		}
		else {
			// heap fixed
			return;
		}
	}
}

Heap::~Heap() {
	if (elements == nullptr)
		return;

	delete[] elements;
}

void Heap::addElement(type element) {
	if (elements == nullptr) {
		elements = new type[1];
		elements[0] = element;
	}
	else {
		type* newElements = new type[currentSize + 1];

		for (int i = 0; i < currentSize; i++) {
			newElements[i] = elements[i];
		}

		newElements[currentSize] = element;

		delete[] elements;
		elements = newElements;

		fixUp(currentSize);
	}

	currentSize++;
}

void Heap::deleteElementFromTop() {
	if (elements == nullptr) 
		return;

	type* newElements = new type[currentSize - 1];

	// last node becomes root
	newElements[0] = elements[currentSize - 1];

	for (int i = 1; i < currentSize - 1; i++) {
		newElements[i] = elements[i];
	}

	delete[] elements;
	elements = newElements;

	fixDown(0);

	currentSize--;
}

int Heap::findElement(type element) {
	// for 0, 2, 6, 14, ... iteration (last indexes on heap levels)
	int currentValue = 0;
	int multiplier = 2;

	bool wasBigger = false;

	for (int i = 0; i < currentSize; i++) {

		if (elements[i] == element)
			return i;
		else if (elements[i] > element)
			wasBigger = true;

		if (i == currentValue) {
			if (!wasBigger)
				return -1;
			else {
				currentValue += multiplier;
				multiplier *= 2;
				wasBigger = false;
			}
		}
	}

	return -1;
}

std::string Heap::toStringTable() {
	std::string result = "[";

	if (currentSize == 0) {
		result += "empty]";
		return result;
	}

	for (int i = 0; i < currentSize; i++) {
		result += std::to_string(elements[i]) + " ";
	}

	result.pop_back(); // deletes extra whitespace
	result += "]";

	return result;
}

std::vector<type> Heap::getVector() {
	if (elements == nullptr) return std::vector<type>();

	std::vector<type> myHeapVector;
	myHeapVector.assign(elements, elements + currentSize);
	return myHeapVector;
}
