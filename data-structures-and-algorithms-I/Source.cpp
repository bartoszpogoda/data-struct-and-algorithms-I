#include "ArrayUnitTesting.h"
#include "BDListUnitTesting.h"
#include "HeapUnitTesting.h"
#include "CLInterface.h"

using namespace std;

bool EXCEL_FORMAT = false, RUN_UNIT_TESTS = false;

int main(int argc, char* argv[]) {

	if (argc == 2 && argv[1][0] == 'E')
		EXCEL_FORMAT = true;
	else if (argc == 2 && argv[1][0] == 'U')
		RUN_UNIT_TESTS = true;
	
	if (RUN_UNIT_TESTS) {
		ArrayUnitTesting::runTests();
		BDListUnitTesting::runTests();
		HeapUnitTesting::runTests();

		system("PAUSE");
	}

	CLInterface::enterCLI(EXCEL_FORMAT);
}
