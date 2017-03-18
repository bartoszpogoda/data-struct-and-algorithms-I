#pragma once
#include "Printable.h"
#include "Type.h"


class Array : public Printable {

private:
	type* elements;
	int currentSize;

public:
	Array();
	~Array();

	int size();

	void addElementAt(type element, int position);
	void addElementFront(type element);
	void addElementEnd(type element);
	void addElementRandom(type element);

	void deleteElementAt(int position);
	void deleteElementFront();
	void deleteElementEnd();
	void deleteElementRandom();

	int findElement(type element);

	std::string toString();

};