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
	// temp visual tests

	system("PAUSE");
	Printer pr;

	cout << "Test add elements to BST: " << endl;
	BRTree* newTree = new BRTree();
	newTree->add(5);
	newTree->add(1);
	newTree->add(8);
	newTree->add(7);
	newTree->add(6);
	newTree->add(2);

	pr.print_tree(newTree->getRoot());
	 
	system("PAUSE");
	cout << "Test rotate right at root: " << endl;
	newTree->rotateRight(newTree->getRoot());
	pr.print_tree(newTree->getRoot());

	system("PAUSE");
}
