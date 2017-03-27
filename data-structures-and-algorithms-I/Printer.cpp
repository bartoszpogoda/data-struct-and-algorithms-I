#include "Printer.h"
#include <sstream>

std::string Printer::do_padding(unsigned index, unsigned mlength) {
	std::string padding;
	if (int((index - 1) / 2) != 0) {
		return (int((index - 1) / 2) % 2 == 0) ?
			(do_padding(int((index - 1) / 2), mlength) + std::string(mlength + 4, ' ') + " ") :
			(do_padding(int((index - 1) / 2), mlength) + std::string(mlength + 3, ' ') + " |");
	}
	return padding;
}

void Printer::printer(std::vector<int> const & heap, unsigned index, unsigned mlength) {
	auto last = heap.size() - 1;
	auto  left = 2 * index + 1;
	auto  right = 2 * index + 2;
	std::cout << " " << heap[index] << " ";
	if (left <= last) {
		auto llength = std::to_string(heap[left]).size();
		std::cout << "---" << std::string(mlength - llength, '-');
		printer(heap, left, mlength);
		if (right <= last) {
			auto rlength = std::to_string(heap[right]).size();
			std::cout << "\n" << do_padding(right, mlength) << std::string(mlength + 3, ' ') << " | ";
			std::cout << "\n" << do_padding(right, mlength) << std::string(mlength + 3, ' ') << " └" <<
				std::string(mlength - rlength, '-');
			printer(heap, right, mlength);
		}
	}
}

int Printer::max_depth(BRTreeNode * n) {
	if (!n) return 0;
	return 1 + std::max(max_depth(n->getLeftChild()), max_depth(n->getRightChild()));
}

std::string Printer::printLevel(BRTreeNode * root, int level, std::string gap) {
	if (level == 1) {
		if (root == 0) {
			return gap + "-" + gap;
		}

		std::stringstream out;
		out << root->getData();
		return gap + out.str() + gap;
	}
	else if (level>1) {
		std::string leftStr = printLevel(root ? root->getLeftChild() : 0, level - 1, gap);
		std::string rightStr = printLevel(root ? root->getRightChild() : 0, level - 1, gap);
		return leftStr + " " + rightStr;
	}
	else return "";
}

void Printer::print_heap(std::vector<int> & heap) {
	unsigned mlength = 0;
	for (int & element : heap) {
		auto clength = std::to_string(element).size();
		if (clength > mlength) {
			mlength = std::to_string(element).size();
		}
	}
	std::cout << std::string(mlength - std::to_string(heap[0]).size(), ' ');
	printer(heap, 0, mlength);
}

void Printer::print_tree(BRTreeNode * root) {
	int depth = max_depth(root);

	for (int i = 1; i <= depth; i++) {
		std::string gap = "";
		for (int j = 0; j<pow(2, depth - i) - 1; j++) {
			gap += " ";
		}
		std::string levelNodes = printLevel(root, i, gap);
		std::cout << levelNodes << std::endl;
	}
}
