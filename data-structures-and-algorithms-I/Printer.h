#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

// implementation of heap printing:
// author: Veritas  http://stackoverflow.com/a/20933103

class Printer {
private:
	std::string do_padding(unsigned index, unsigned mlength);
	void printer(std::vector<int> const & heap, unsigned index, unsigned mlength);
public:
	void print_heap(std::vector<int> & heap);
};
