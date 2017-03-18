#include "Array.h"
#include <string>

Array::Array() {
	currentSize = 0;
	elements = nullptr;
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

int Array::size()
{
	return currentSize;
}

std::string Array::toString()
{
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

