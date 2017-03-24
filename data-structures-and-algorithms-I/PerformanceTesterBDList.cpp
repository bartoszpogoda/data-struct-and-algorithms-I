#include "PerformanceTester.h"
#include "BDList.h"
#include <time.h>
#include <string>
#include <vector>
#include <random>
#include <algorithm>


void PerformanceTester::addElementToFrontOfBDList(int arraySize, type valuesMin, type valuesMax, int iterations) {

	timer.resetMemory();
	for (int i = 0; i < iterations; i++) {
		BDList* testBDList = new BDList();

		for (int j = 0; j < arraySize; j++)
			testBDList->addElementEnd(valuesMin + rand() % valuesMax);

		type elementToAdd = valuesMin + rand() % valuesMax;

		timer.startTimer();
		testBDList->addElementFront(elementToAdd);
		timer.endTimer();

		delete testBDList;
	}
	timer.divideMemory(iterations);
	if (fileOutput)
		std::cout << arraySize << ";" << timer.timeMicroSecondsMemory() << std::endl;
	else
		std::cout << "Sredni czas (" << iterations << " iteracji) dodawania elementu na poczatek " << arraySize << " elementowej listy [" << valuesMin << ", " << valuesMax << "): " << timer.timeMicroSecondsMemory() << " uS" << std::endl;
}

void PerformanceTester::addElementToTheEndOfBDList(int arraySize, type valuesMin, type valuesMax, int iterations) {

	timer.resetMemory();
	for (int i = 0; i < iterations; i++) {
		BDList* testBDList = new BDList();

		for (int j = 0; j < arraySize; j++)
			testBDList->addElementEnd(valuesMin + rand() % valuesMax);

		type elementToAdd = valuesMin + rand() % valuesMax;

		timer.startTimer();
		testBDList->addElementEnd(elementToAdd);
		timer.endTimer();

		delete testBDList;
	}
	timer.divideMemory(iterations);
	if (fileOutput)
		std::cout << arraySize << ";" << timer.timeMicroSecondsMemory() << std::endl;
	else
		std::cout << "Sredni czas (" << iterations << " iteracji) dodawania elementu na koniec " << arraySize << " elementowej listy [" << valuesMin << ", " << valuesMax << "): " << timer.timeMicroSecondsMemory() << " uS" << std::endl;
}

void PerformanceTester::addElementToTheRandomOfBDList(int arraySize, type valuesMin, type valuesMax, int iterations) {

	timer.resetMemory();
	for (int i = 0; i < iterations; i++) {
		BDList* testBDList = new BDList();

		for (int j = 0; j < arraySize; j++)
			testBDList->addElementEnd(valuesMin + rand() % valuesMax);

		type elementToAdd = valuesMin + rand() % valuesMax;
		int randomPosition = rand() % arraySize;

		timer.startTimer();
		testBDList->addElementAt(elementToAdd, randomPosition);
		timer.endTimer();

		delete testBDList;
	}
	timer.divideMemory(iterations);
	if (fileOutput)
		std::cout << arraySize << ";" << timer.timeMicroSecondsMemory() << std::endl;
	else
		std::cout << "Sredni czas (" << iterations << " iteracji) dodawania elementu na losowa pozycje " << arraySize << " elementowej listy [" << valuesMin << ", " << valuesMax << "): " << timer.timeMicroSecondsMemory() << " uS" << std::endl;
}

void PerformanceTester::deleteElementFromTheFrontOfBDList(int arraySize, type valuesMin, type valuesMax, int iterations) {

	timer.resetMemory();
	for (int i = 0; i < iterations; i++) {
		BDList* testBDList = new BDList();

		for (int j = 0; j < arraySize; j++)
			testBDList->addElementEnd(valuesMin + rand() % valuesMax);

		timer.startTimer();
		testBDList->deleteElementFront();
		timer.endTimer();

		delete testBDList;
	}
	timer.divideMemory(iterations);
	if (fileOutput)
		std::cout << arraySize << ";" << timer.timeMicroSecondsMemory() << std::endl;
	else
		std::cout << "Sredni czas (" << iterations << " iteracji) usuwania elementu z poczatku " << arraySize << " elementowej listy [" << valuesMin << ", " << valuesMax << "): " << timer.timeMicroSecondsMemory() << " uS" << std::endl;
}

void PerformanceTester::deleteElementFromTheEndOfBDList(int arraySize, type valuesMin, type valuesMax, int iterations) {

	timer.resetMemory();
	for (int i = 0; i < iterations; i++) {
		BDList* testBDList = new BDList();

		for (int j = 0; j < arraySize; j++)
			testBDList->addElementEnd(valuesMin + rand() % valuesMax);

		timer.startTimer();
		testBDList->deleteElementEnd();
		timer.endTimer();

		delete testBDList;
	}
	timer.divideMemory(iterations);
	if (fileOutput)
		std::cout << arraySize << ";" << timer.timeMicroSecondsMemory() << std::endl;
	else
		std::cout << "Sredni czas (" << iterations << " iteracji) usuwania elementu z konca " << arraySize << " elementowej listy [" << valuesMin << ", " << valuesMax << "): " << timer.timeMicroSecondsMemory() << " uS" << std::endl;
}

void PerformanceTester::deleteElementFromTheRandomOfBDList(int arraySize, type valuesMin, type valuesMax, int iterations) {

	timer.resetMemory();
	for (int i = 0; i < iterations; i++) {
		BDList* testBDList = new BDList();

		for (int j = 0; j < arraySize; j++)
			testBDList->addElementEnd(valuesMin + rand() % valuesMax);

		type elementToAdd = valuesMin + rand() % valuesMax;
		int randomPosition = rand() % arraySize;

		timer.startTimer();
		testBDList->deleteElementAt(randomPosition);
		timer.endTimer();

		delete testBDList;
	}
	timer.divideMemory(iterations);
	if (fileOutput)
		std::cout << arraySize << ";" << timer.timeMicroSecondsMemory() << std::endl;
	else
		std::cout << "Sredni czas (" << iterations << " iteracji) usuwania elementu z losowej pozycji " << arraySize << " elementowej listy [" << valuesMin << ", " << valuesMax << "): " << timer.timeMicroSecondsMemory() << " uS" << std::endl;
}

void PerformanceTester::findElementInBDList(int arraySize, type valuesMin, int iterations) {

	std::vector<type> dataVec = std::vector<type>(arraySize);
	int n = valuesMin;
	std::generate(dataVec.begin(), dataVec.end(), [&n] {return n++; });
	auto engine = std::default_random_engine{};

	timer.resetMemory();
	for (int i = 0; i < iterations; i++) {
		BDList* testBDList = new BDList();

		std::shuffle(dataVec.begin(), dataVec.end(), engine);
		for (int j = 0; j < arraySize; j++)
			testBDList->addElementEnd(dataVec[j]);

		type randomElement = dataVec[rand() % arraySize];

		timer.startTimer();
		int found = testBDList->findElement(randomElement);
		timer.endTimer();

		delete testBDList;
	}
	timer.divideMemory(iterations);
	if (fileOutput)
		std::cout << arraySize << ";" << timer.timeMicroSecondsMemory() << std::endl;
	else
		std::cout << "Sredni czas (" << iterations << " iteracji) znajdywania elementu " << arraySize << " elementowej listy [" << valuesMin << ", " << valuesMin + arraySize << "): " << timer.timeMicroSecondsMemory() << " uS" << std::endl;

}
