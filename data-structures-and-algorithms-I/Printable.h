#pragma once
#include <iostream>

class Printable {
public:
	virtual std::string toString() = 0;
};