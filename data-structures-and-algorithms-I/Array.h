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
	void addElement(type element);
	int size();
	
	std::string toString();

};