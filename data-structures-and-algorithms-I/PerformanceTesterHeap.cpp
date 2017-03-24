#include "PerformanceTester.h"
#include "Heap.h"
#include <time.h>
#include <string>
#include <vector>
#include <random>
#include <algorithm>


void PerformanceTester::addElementToTheHeap(int arraySize, type valuesMin, type valuesMax, int iterations) {
	timer.resetMemory();
	for (int i = 0; i < iterations; i++) {
		Heap* testHeap = new Heap();

		for (int j = 0; j < arraySize; j++)
			testHeap->addElement(valuesMin + rand() % valuesMax);

		type elementToAdd = valuesMin + rand() % valuesMax;

		timer.startTimer();
		testHeap->addElement(elementToAdd);
		timer.endTimer();

		delete testHeap;
	}
	timer.divideMemory(iterations);
	if (fileOutput)
		std::cout << arraySize << ";" << timer.timeMicroSecondsMemory() << std::endl;
	else
		std::cout << "Sredni czas (" << iterations << " iteracji) dodawania elementu do " << arraySize << " elementowego kopca [" << valuesMin << ", " << valuesMax << "): " << timer.timeMicroSecondsMemory() << " uS" << std::endl;

}

void PerformanceTester::deleteRootFromTheHeap(int arraySize, type valuesMin, type valuesMax, int iterations) {
	timer.resetMemory();
	for (int i = 0; i < iterations; i++) {
		Heap* testHeap = new Heap();

		for (int j = 0; j < arraySize; j++)
			testHeap->addElement(valuesMin + rand() % valuesMax);

		timer.startTimer();
		testHeap->deleteElementFromTop();
		timer.endTimer();

		delete testHeap;
	}
	timer.divideMemory(iterations);
	if (fileOutput)
		std::cout << arraySize << ";" << timer.timeMicroSecondsMemory() << std::endl;
	else
		std::cout << "Sredni czas (" << iterations << " iteracji) usuwania korzenia " << arraySize << " elementowego kopca [" << valuesMin << ", " << valuesMax << "): " << timer.timeMicroSecondsMemory() << " uS" << std::endl;

}

void PerformanceTester::findElementInHeap(int arraySize, type valuesMin, int iterations) {
	std::vector<type> dataVec = std::vector<type>(arraySize);
	int n = valuesMin;
	std::generate(dataVec.begin(), dataVec.end(), [&n] {return n++; });
	auto engine = std::default_random_engine{};

	timer.resetMemory();
	for (int i = 0; i < iterations; i++) {
		Heap* testHeap = new Heap();

		std::shuffle(dataVec.begin(), dataVec.end(), engine);
		for (int j = 0; j < arraySize; j++)
			testHeap->addElement(dataVec[j]);

		type randomElement = dataVec[rand() % arraySize];

		timer.startTimer();
		int found = testHeap->findElement(randomElement);
		timer.endTimer();

		delete testHeap;
	}
	timer.divideMemory(iterations);
	if (fileOutput)
		std::cout << arraySize << ";" << timer.timeMicroSecondsMemory() << std::endl;
	else
		std::cout << "Sredni czas (" << iterations << " iteracji) znajdywania elementu " << arraySize << " elementowego kopca [" << valuesMin << ", " << valuesMin + arraySize << "): " << timer.timeMicroSecondsMemory() << " uS" << std::endl;

}