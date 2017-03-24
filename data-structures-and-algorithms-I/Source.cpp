#include "ArrayUnitTesting.h"
#include "BDListUnitTesting.h"
#include "HeapUnitTesting.h"
#include "CLInterface.h"

using namespace std;

const bool RUN_TESTS = false;
bool FILE_OUTPUT_RUN = false;
//-------------------------------------------------------------------------

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

}
