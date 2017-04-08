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
			testBDList->addEnd(valuesMin + (bigNumberDist(gen) % (valuesMax - valuesMin)));

		type elementToAdd = valuesMin + (bigNumberDist(gen) % (valuesMax - valuesMin));

		timer.startTimer();
		testBDList->addFront(elementToAdd);
		timer.endTimer();

		delete testBDList;
	}
	timer.divideMemory(iterations);
	if (excelFormat)
		std::cout << arraySize << ";" << timer.timeMicroSecondsMemory() << std::endl;
	else
		std::cout << "Sredni czas (" << iterations << " iteracji) dodawania elementu na poczatek " << arraySize << " elementowej listy [" << valuesMin << ", " << valuesMax << "): " << timer.timeMicroSecondsMemory() << " uS" << std::endl;
}

void PerformanceTester::addElementToTheEndOfBDList(int arraySize, type valuesMin, type valuesMax, int iterations) {

	timer.resetMemory();
	for (int i = 0; i < iterations; i++) {
		BDList* testBDList = new BDList();

		for (int j = 0; j < arraySize; j++)
			testBDList->addEnd(valuesMin + (bigNumberDist(gen) % (valuesMax - valuesMin)));

		type elementToAdd = valuesMin + (bigNumberDist(gen) % (valuesMax - valuesMin));

		timer.startTimer();
		testBDList->addEnd(elementToAdd);
		timer.endTimer();

		delete testBDList;
	}
	timer.divideMemory(iterations);
	if (excelFormat)
		std::cout << arraySize << ";" << timer.timeMicroSecondsMemory() << std::endl;
	else
		std::cout << "Sredni czas (" << iterations << " iteracji) dodawania elementu na koniec " << arraySize << " elementowej listy [" << valuesMin << ", " << valuesMax << "): " << timer.timeMicroSecondsMemory() << " uS" << std::endl;
}

void PerformanceTester::addElementToTheRandomOfBDList(int arraySize, type valuesMin, type valuesMax, int iterations) {

	timer.resetMemory();
	for (int i = 0; i < iterations; i++) {
		BDList* testBDList = new BDList();

		for (int j = 0; j < arraySize; j++)
			testBDList->addEnd(valuesMin + (bigNumberDist(gen) % (valuesMax - valuesMin)));

		type elementToAdd = valuesMin + (bigNumberDist(gen) % (valuesMax - valuesMin));
		int randomPosition = bigNumberDist(gen) % arraySize;

		timer.startTimer();
		testBDList->addAt(elementToAdd, randomPosition);
		timer.endTimer();

		delete testBDList;
	}
	timer.divideMemory(iterations);
	if (excelFormat)
		std::cout << arraySize << ";" << timer.timeMicroSecondsMemory() << std::endl;
	else
		std::cout << "Sredni czas (" << iterations << " iteracji) dodawania elementu na losowa pozycje " << arraySize << " elementowej listy [" << valuesMin << ", " << valuesMax << "): " << timer.timeMicroSecondsMemory() << " uS" << std::endl;
}

void PerformanceTester::deleteElementFromTheFrontOfBDList(int arraySize, type valuesMin, type valuesMax, int iterations) {

	timer.resetMemory();
	for (int i = 0; i < iterations; i++) {
		BDList* testBDList = new BDList();

		for (int j = 0; j < arraySize; j++)
			testBDList->addEnd(valuesMin + (bigNumberDist(gen) % (valuesMax - valuesMin)));

		timer.startTimer();
		testBDList->deleteFront();
		timer.endTimer();

		delete testBDList;
	}
	timer.divideMemory(iterations);
	if (excelFormat)
		std::cout << arraySize << ";" << timer.timeMicroSecondsMemory() << std::endl;
	else
		std::cout << "Sredni czas (" << iterations << " iteracji) usuwania elementu z poczatku " << arraySize << " elementowej listy [" << valuesMin << ", " << valuesMax << "): " << timer.timeMicroSecondsMemory() << " uS" << std::endl;
}

void PerformanceTester::deleteElementFromTheEndOfBDList(int arraySize, type valuesMin, type valuesMax, int iterations) {

	timer.resetMemory();
	for (int i = 0; i < iterations; i++) {
		BDList* testBDList = new BDList();

		for (int j = 0; j < arraySize; j++)
			testBDList->addEnd(valuesMin + (bigNumberDist(gen) % (valuesMax - valuesMin)));

		timer.startTimer();
		testBDList->deleteEnd();
		timer.endTimer();

		delete testBDList;
	}
	timer.divideMemory(iterations);
	if (excelFormat)
		std::cout << arraySize << ";" << timer.timeMicroSecondsMemory() << std::endl;
	else
		std::cout << "Sredni czas (" << iterations << " iteracji) usuwania elementu z konca " << arraySize << " elementowej listy [" << valuesMin << ", " << valuesMax << "): " << timer.timeMicroSecondsMemory() << " uS" << std::endl;
}

void PerformanceTester::deleteElementFromTheRandomOfBDList(int arraySize, type valuesMin, type valuesMax, int iterations) {

	timer.resetMemory();
	for (int i = 0; i < iterations; i++) {
		BDList* testBDList = new BDList();

		for (int j = 0; j < arraySize; j++)
			testBDList->addEnd(valuesMin + (bigNumberDist(gen) % (valuesMax - valuesMin)));

		type elementToAdd = valuesMin + (bigNumberDist(gen) % (valuesMax - valuesMin));
		int randomPosition = bigNumberDist(gen) % arraySize;

		timer.startTimer();
		testBDList->deleteAt(randomPosition);
		timer.endTimer();

		delete testBDList;
	}
	timer.divideMemory(iterations);
	if (excelFormat)
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
			testBDList->addEnd(dataVec[j]);

		type randomElement = dataVec[bigNumberDist(gen) % arraySize];

		timer.startTimer();
		int found = testBDList->find(randomElement);
		timer.endTimer();

		delete testBDList;
	}
	timer.divideMemory(iterations);
	if (excelFormat)
		std::cout << arraySize << ";" << timer.timeMicroSecondsMemory() << std::endl;
	else
		std::cout << "Sredni czas (" << iterations << " iteracji) znajdywania elementu " << arraySize << " elementowej listy [" << valuesMin << ", " << valuesMin + arraySize << "): " << timer.timeMicroSecondsMemory() << " uS" << std::endl;

}
