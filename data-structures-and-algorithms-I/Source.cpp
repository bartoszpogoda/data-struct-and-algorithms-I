#include "ArrayUnitTesting.h"
#include "BDListUnitTesting.h"
#include "HeapUnitTesting.h"
#include "CLInterface.h"
#include "Printer.h"

#include <iomanip>
#include "BRTree.h"
#include <sstream>
#include <list>



using namespace std;

const bool RUN_TESTS = true;
bool FILE_OUTPUT_RUN = false;
//-------------------------------------------


int main(int argc, char* argv[]) {

	if (argc == 2 && argv[1][0] == 'D')
		FILE_OUTPUT_RUN = true;
	
	
	if (RUN_TESTS) {
		ArrayUnitTesting::runTests();
		BDListUnitTesting::runTests();
		HeapUnitTesting::runTests();

		system("PAUSE");
	}

	//CLI 

	CLInterface::enterCLI(FILE_OUTPUT_RUN);

	//CLI END


	system("PAUSE");

	BRTree* brTree = new BRTree();

	BRTreeNode* A = new BRTreeNode(6);
	BRTreeNode* B = new BRTreeNode(4);
	BRTreeNode* BL = new BRTreeNode(3);
	BRTreeNode* BR = new BRTreeNode(5);
	BRTreeNode* AR = new BRTreeNode(7);
	BRTreeNode* ARL = new BRTreeNode(6);
	BRTreeNode* ARR = new BRTreeNode(8);


	A->setLeftChild(B);
	A->setRightChild(AR);
	B->setLeftChild(BL);
	B->setRightChild(BR);
	B->setParent(A);
	AR->setParent(A);
	BL->setParent(B);
	BR->setParent(B);

	ARL->setParent(AR);
	ARR->setParent(AR);
	AR->setLeftChild(ARL);
	AR->setRightChild(ARR);

	Printer pr;
	pr.print_tree(A);

	system("PAUSE");
	brTree->rotateRight(A);
	brTree->rotateLeft(B);
	brTree->rotateLeft(B);
	brTree->rotateLeft(B);
	brTree->rotateLeft(B);
	brTree->rotateLeft(B);
	brTree->rotateLeft(B);

	pr.print_tree(A);

	system("PAUSE");

}
