#include "PerformanceTester.h"
#include "Array.h"
#include <time.h>
#include <string>

void PerformanceTester::addElementToFrontOfArray(int arraySize, type valuesMin, type valuesMax, int iterations) {

	Array* testArray = new Array();

	timer.resetMemory();
	for (int i = 0; i < iterations; i++) {
		srand(time(NULL));
		for (int j = 0; j < arraySize; j++)
			testArray->addElementEnd(valuesMin + rand() % valuesMax);

		type elementToAdd = valuesMin + rand() % valuesMax;

		timer.startTimer();
		testArray->addElementFront(elementToAdd);
		timer.endTimer();
	}
	timer.divideMemory(iterations);
	std::cout << "Sredni czas (" << iterations << " iteracji) dodawania elementu na poczatek " << arraySize << " elementowej tablicy [" << valuesMin << ", " << valuesMax << "): " << timer.timeMicroSecondsMemory() << " uS" << std::endl;

	delete testArray;
}
