#include "PerformanceTester.h"
#include "Heap.h"
#include <time.h>
#include <string>
#include <vector>
#include <random>
#include "Printer.h"
#include <algorithm>


void PerformanceTester::addElementToTheHeap(int arraySize, type valuesMin, type valuesMax, int iterations) {
	timer.resetMemory();
	for (int i = 0; i < iterations; i++) {
		type* dataArray = generateTestData(arraySize, valuesMin, valuesMax);
		Heap* testHeap = new Heap(dataArray, arraySize);

		type elementToAdd = valuesMin + (bigNumberDist(gen) % (valuesMax - valuesMin));

		timer.startTimer(); 
		testHeap->add(elementToAdd);
		timer.endTimer();

		if (testHeap->validate(0) == false)
			std::cout << "Blad!";

		delete testHeap;
		delete dataArray;
	}
	timer.divideMemory(iterations);
	if (excelFormat)
		std::cout << arraySize << ";" << timer.timeMicroSecondsMemory() << std::endl;
	else
		std::cout << "Sredni czas (" << iterations << " iteracji) dodawania elementu do " << arraySize << " elementowego kopca [" << valuesMin << ", " << valuesMax << "): " << timer.timeMicroSecondsMemory() << " uS" << std::endl;

}

void PerformanceTester::deleteRootFromTheHeap(int arraySize, type valuesMin, type valuesMax, int iterations) {
	timer.resetMemory();
	for (int i = 0; i < iterations; i++) {
		type* dataArray = generateTestData(arraySize, valuesMin, valuesMax);
		Heap* testHeap = new Heap(dataArray, arraySize);

		timer.startTimer();
		testHeap->deleteRoot();
		timer.endTimer();

		delete testHeap;
		delete dataArray;
	}
	timer.divideMemory(iterations);
	if (excelFormat)
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

		std::shuffle(dataVec.begin(), dataVec.end(), engine);
		type* dataArray = new type[arraySize];
		for (int j = 0; j < arraySize; j++)
			dataArray[j] = dataVec[j];

		Heap* testHeap = new Heap(dataArray, arraySize);

		type randomElement = dataVec[bigNumberDist(gen) % arraySize];

		timer.startTimer();
		int found = testHeap->find(randomElement);
		timer.endTimer();


		delete testHeap;
		delete dataArray;
	}
	timer.divideMemory(iterations);
	if (excelFormat)
		std::cout << arraySize << ";" << timer.timeMicroSecondsMemory() << std::endl;
	else
		std::cout << "Sredni czas (" << iterations << " iteracji) znajdywania elementu " << arraySize << " elementowego kopca [" << valuesMin << ", " << valuesMin + arraySize << "): " << timer.timeMicroSecondsMemory() << " uS" << std::endl;

}