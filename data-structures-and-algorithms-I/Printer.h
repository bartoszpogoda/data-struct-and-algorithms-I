#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "BSTreeNode.h"
#include "Heap.h"
#include <algorithm>

// implementation of tree printing:
// source: http://eduinf.waw.pl/inf/alg/001_search/0116.php
// i've modified mentioned implementation of tree printing for heap printing needs

class Printer {
	std::string cr, cl, cp;
public:
	Printer();
	void print_heap(std::string sp, std::string sn, Heap* v, int id);
	void print_tree(std::string sp, std::string sn, BSTreeNode* root);
};
