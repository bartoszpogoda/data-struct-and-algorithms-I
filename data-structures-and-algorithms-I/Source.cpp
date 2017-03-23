#include "ArrayTesting.h"
#include "BDListTesting.h"
#include "HeapTesting.h"
#include "CLInterface.h"

using namespace std;

const bool RUN_TESTS = true;

//-------------------------------------------------------------------------

int main() {
	
	if (RUN_TESTS) {
		ArrayTesting::runTests();
		BDListTesting::runTests();
		HeapTesting::runTests();

		system("PAUSE");
	}

	//CLI 

	CLInterface::enterCLI();

	//CLI END

}
