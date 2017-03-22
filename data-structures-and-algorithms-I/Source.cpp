
#include "ArrayTesting.h"
#include "CLInterface.h"

using namespace std;

const bool RUN_TESTS = false;


//-------------------------------------------------------------------------


int main() {
	
	if (RUN_TESTS) {
		ArrayTesting::runTests();
		system("PAUSE");
	}

	//CLI 

	CLInterface::enterCLI();

	//CLI END
	

}
