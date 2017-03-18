
#include "ArrayTesting.h"
#include "CLInterface.h"

using namespace std;

const bool RUN_TESTS = true;


//-------------------------------------------------------------------------


int main() {
	
	if (RUN_TESTS) {
		ArrayTesting::runTests();
	}

	//CLI 

	CLInterface::enterCLI();

	//CLI END
	

}
