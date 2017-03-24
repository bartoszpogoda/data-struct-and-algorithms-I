#pragma once
#include <iostream>
#include "Array.h"
#include "BDList.h"
#include "Heap.h"

class FileReader {
public:
	std::string readArray(std::string filename, Array* &array);
	std::string readBDList(std::string filename, BDList* &bdList);
	std::string readHeap(std::string filename, Heap* &heap);
};