#include "Array.h"
#include <string>
#include <time.h>      

Array::Array() {
	currentSize = 0;
	elements = nullptr;
}

Array::~Array() {
	delete[] elements;
}

void Array::addElement(type element) {
	if (currentSize == 0) {
		elements = new type[++currentSize];
		elements[0] = element;

		return;
	} 

	type* newElements = new type[currentSize + 1];
	
	for (int i = 0; i < currentSize; i++) {
		newElements[i] = elements[i];
	}

	newElements[currentSize++] = element;

	delete[] elements;
	elements = newElements;

}

void Array::addElementFront(type element) {
	if (currentSize == 0) {
		elements = new type[++currentSize];
		elements[0] = element;

		return;
	}

	type* newElements = new type[currentSize + 1];

	newElements[0] = element;

	for (int i = 0; i < currentSize; i++) {
		newElements[i+1] = elements[i];
	}

	currentSize++;

	delete[] elements;
	elements = newElements;
}

void Array::addElementRandom(type element) {
	srand(time(NULL));

	int position = rand() % currentSize;
	addElementAt(element, position);

}

void Array::addElementAt(type element, int position) {
	// handling wrong input
	if (position > currentSize) {
		addElement(element);
		return;
	}
	else if (position < 0) {
		addElementFront(element);
		return;
	}

	type* newElements = new type[currentSize + 1];

	int i = 0;
	for ( ; i < position; i++) {
		newElements[i] = elements[i];
	}

	newElements[i] = element;

	for (; i < currentSize; i++) {
		newElements[i+1] = elements[i];
	}

	currentSize++;

	delete[] elements;
	elements = newElements;
}

int Array::size() {
	return currentSize;
}

std::string Array::toString() {
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

