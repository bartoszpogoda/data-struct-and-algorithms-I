#pragma once
#include "Type.h"
#include <iostream>

class Array{

private:
	type* elements;
	int currentSize;

public:
	Array();
	~Array();

	int size();

	void addAt(type element, int position);
	void addFront(type element);
	void addEnd(type element);
	void addAtRandom(type element);

	void deleteAt(int position);
	void deleteFront();
	void deleteEnd();
	void deleteRandom();

	int find(type element);
	type get(int position) { return elements[position]; }

	std::string toString();

};