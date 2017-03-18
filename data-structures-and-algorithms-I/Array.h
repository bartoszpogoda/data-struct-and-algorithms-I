#pragma once
#include <stdint.h>
#include "Printable.h"

typedef int32_t type;

class Array : public Printable {

private:
	type* elements;
	int currentSize;

public:
	Array();
	~Array();

	int size();

	void addElementEnd(type element);
	void addElementFront(type element);
	void addElementRandom(type element);
	void addElementAt(type element, int position);

	void deleteElementAt(int position);
	void deleteElementEnd();
	void deleteElementFront();
	void deleteElementRandom();

	std::string toString();

};