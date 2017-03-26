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

void Array::addEnd(type element) {
	addAt(element, currentSize);
}

void Array::addFront(type element) {
	addAt(element, 0);
}

void Array::addAtRandom(type element) {	
	srand(time(NULL));

	int position = rand() % currentSize;
	addAt(element, position);

}

void Array::addAt(type element, int position) {
	// handles wrong input
	if (position > currentSize) {
		position = currentSize;
	}
	else if (position < 0) {
		position = 0;
	}

	if (currentSize == 0) {
		elements = new type[++currentSize];
		elements[0] = element;

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

void Array::deleteAt(int position) {
	type deletedElement = -1;

	if (position > currentSize) {
		position = currentSize;
	} else if (position < 0) {
		position = 0;
	}

	if (currentSize == 0)
		return;

	type* newElements = new type[currentSize - 1];

	int i = 0;
	for (; i < position; i++) {
		newElements[i] = elements[i];
	}

	for (; i < currentSize - 1; i++) {
		newElements[i] = elements[i+1];
	}

	currentSize--;

	delete[] elements;
	elements = newElements;
}

void Array::deleteEnd() {
	deleteAt(currentSize - 1);
}

void Array::deleteFront() {
	deleteAt(0);
}

void Array::deleteRandom() {
	srand(time(NULL));

	int position = rand() % currentSize;
	deleteAt(position);
}

int Array::find(type element) {
	for (int i = 0; i < currentSize; i++) {
		if (element == elements[i])
			return i;
	}
	return -1;
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

