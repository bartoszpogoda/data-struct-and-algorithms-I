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

	/**
	Adds an element at the end of the array.
	*/
	void addElement(type element);

	/**
	Adds an element to the front of the array.
	*/
	void addElementFront(type element);

	/**
	Adds an element to the random position of the array.
	*/
	void addElementRandom(type element);

	/**
	Adds an element at specified position of the array.
	*/
	void addElementAt(type element, int position);

	int size();
	
	std::string toString();

};