#include "Printer.h"
#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

Printer::Printer() {
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
}

void Printer::print_heap(std::string sp, std::string sn, Heap * v, int id) {
	std::string s;

	if (id < v->size()) {
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		print_heap(s + cp, cr, v, v->rightChild(id));

		s = s.substr(0, sp.length() - 2);
		std::cout << s << sn << v->get(id) << std::endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		print_heap(s + cp, cl, v, v->leftChild(id));
	}
}

void Printer::print_tree(std::string sp, std::string sn, BSTreeNode * v) {
	std::string s;

	if (v) {
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		print_tree(s + cp, cr, v->getRightChild());

		s = s.substr(0, sp.length() - 2);
		std::cout << s << sn << v->getData() << std::endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		print_tree(s + cp, cl, v->getLeftChild());
	}
}

