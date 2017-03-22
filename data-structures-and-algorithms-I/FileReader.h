#pragma once
#include <iostream>
#include "Array.h"

class FileReader {
public:
	std::string readArray(std::string filename, Array* &array);

};