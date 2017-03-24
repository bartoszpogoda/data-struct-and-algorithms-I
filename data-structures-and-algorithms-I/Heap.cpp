#include "Heap.h"
#include <string>

void Heap::fixUp(int nodeId) {
	while (parent(nodeId) >= 0) {
		// czy rodzic ma mniejsza wartosc
		if (elements[parent(nodeId)] < elements[nodeId]) {
			// zamiana z rodzicem
			type dataHolder = elements[nodeId];
			elements[nodeId] = elements[parent(nodeId)];
			elements[parent(nodeId)] = dataHolder;

			// dla nastepnej iteracji
			nodeId = parent(nodeId);
		}
		else {
			// kopiec naprawiony
			return;
		}
	}
}

void Heap::fixDown(int nodeId) {
	while (leftChild(nodeId) < currentSize) {
		// czy lewe dziecko ma wieksza wartosc 
		if (elements[leftChild(nodeId)] > elements[nodeId]) {
			// czy prawe dziecko istnieje i ma wieksza wartosc od lewego
			if (rightChild(nodeId) < currentSize && elements[rightChild(nodeId)] > elements[leftChild(nodeId)]) {
				// zamiana z prawym dzieckiem
				type dataHolder = elements[nodeId];
				elements[nodeId] = elements[rightChild(nodeId)];
				elements[rightChild(nodeId)] = dataHolder;

				// dla nastepnej iteracji
				nodeId = rightChild(nodeId);
			}
			else {
				// zamiana z lewym dzieckiem
				type dataHolder = elements[nodeId];
				elements[nodeId] = elements[leftChild(nodeId)];
				elements[leftChild(nodeId)] = dataHolder;

				// dla nastepnej iteracji
				nodeId = leftChild(nodeId);
			}

		} // czy prawe dziecko istnieje i ma wieksza wartosc
		else if (rightChild(nodeId) < currentSize && elements[rightChild(nodeId)] > elements[nodeId]) {
			// zamiana z prawym dzieckiem
			type dataHolder = elements[nodeId];
			elements[nodeId] = elements[rightChild(nodeId)];
			elements[rightChild(nodeId)] = dataHolder;

			// dla nastepnej iteracji
			nodeId = rightChild(nodeId);
		}
		else {
			// kopiec naprawiony
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

	// ostatni lisc staje sie korzeniem
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
	return 0;
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
