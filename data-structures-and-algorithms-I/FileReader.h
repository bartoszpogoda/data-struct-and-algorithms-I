#pragma once
#include <iostream>
#include "Array.h"
#include "BDList.h"

class FileReader {
public:
	std::string readArray(std::string filename, Array* &array);
	std::string readBDList(std::string filename, BDList* &bdList);
};