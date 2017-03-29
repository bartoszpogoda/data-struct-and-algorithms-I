#pragma once
#include <iostream>
#include "Array.h"
#include "BDList.h"
#include "Heap.h"
#include "BRTree.h"

// source: http://staff.iiar.pwr.wroc.pl/antoni.sterna/sdizo/SDiZO_file.pdf

class FileReader {
public:
	std::string readArray(std::string filename, Array* &array);
	std::string readBDList(std::string filename, BDList* &bdList);
	std::string readHeap(std::string filename, Heap* &heap);
	std::string readBRTree(std::string filename, BRTree* &brTree);
};