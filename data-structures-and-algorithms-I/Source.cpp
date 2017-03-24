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

		std::cout << "Timer memory test, time should be 2s, then 1,5s" << std::endl;
		Timer timer = Timer();
		timer.resetMemory();
		timer.startTimer();
		_sleep(1000);
		timer.endTimer();
		timer.startTimer();
		_sleep(1000);
		timer.endTimer();
		std::cout << timer.timeSecondsMemory() << "s";
		timer.resetMemory();
		timer.startTimer();
		_sleep(3000);
		timer.endTimer();
		timer.divideMemory(2);
		std::cout << ", then " << timer.timeSecondsMemory() << "s" << endl;
		timer.resetMemory();

		system("PAUSE");
	}

	
	//CLI 

	CLInterface::enterCLI();

	//CLI END

}
