#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "BRTreeNode.h"
#include <algorithm>

// implementation of heap printing:
// author: Veritas  http://stackoverflow.com/a/20933103

// implementation of tree printing:
// author: raven_raven, modified by Matthieu M. http://stackoverflow.com/a/15854194
// and then modified by me for BRT needs
class Printer {
private:
	std::string do_padding(unsigned index, unsigned mlength);
	void printer(std::vector<int> const & heap, unsigned index, unsigned mlength);
	int max_depth(BRTreeNode* n);

	std::string printLevel(BRTreeNode *root, int level, std::string gap);
public:
	void print_heap(std::vector<int> & heap);
	void print_tree(BRTreeNode* root);
};
