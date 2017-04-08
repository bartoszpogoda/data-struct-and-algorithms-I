#include "PerformanceTester.h"
#include "Array.h"
#include <time.h>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

void PerformanceTester::addElementToFrontOfArray(int arraySize, type valuesMin, type valuesMax, int iterations) {

	timer.resetMemory();
	for (int i = 0; i < iterations; i++) {
		type* dataArray = generateTestData(arraySize, valuesMin, valuesMax);
		Array* testArray = new Array(dataArray, arraySize);

		type elementToAdd = valuesMin + (bigNumberDist(gen) % (valuesMax - valuesMin));

		timer.startTimer();
		testArray->addFront(elementToAdd);
		timer.endTimer();

		delete testArray;
		delete dataArray;
	}
	timer.divideMemory(iterations);
	if (fileOutput)
		std::cout << arraySize << ";" << timer.timeMicroSecondsMemory() << std::endl;
	else
		std::cout << "Sredni czas (" << iterations << " iteracji) dodawania elementu na poczatek " << arraySize << " elementowej tablicy [" << valuesMin << ", " << valuesMax << "): " << timer.timeMicroSecondsMemory() << " uS" << std::endl;
}

void PerformanceTester::addElementToTheEndOfArray(int arraySize, type valuesMin, type valuesMax, int iterations) {

	timer.resetMemory();
	for (int i = 0; i < iterations; i++) {
		type* dataArray = generateTestData(arraySize, valuesMin, valuesMax);
		Array* testArray = new Array(dataArray, arraySize);

		type elementToAdd = valuesMin + (bigNumberDist(gen) % (valuesMax - valuesMin));

		timer.startTimer();
		testArray->addEnd(elementToAdd);
		timer.endTimer();

		delete testArray;
		delete dataArray;
	}
	timer.divideMemory(iterations);
	if (fileOutput)
		std::cout << arraySize << ";" << timer.timeMicroSecondsMemory() << std::endl;
	else
		std::cout << "Sredni czas (" << iterations << " iteracji) dodawania elementu na koniec " << arraySize << " elementowej tablicy [" << valuesMin << ", " << valuesMax << "): " << timer.timeMicroSecondsMemory() << " uS" << std::endl;
}

void PerformanceTester::addElementToTheRandomOfArray(int arraySize, type valuesMin, type valuesMax, int iterations) {

	timer.resetMemory();
	for (int i = 0; i < iterations; i++) {
		type* dataArray = generateTestData(arraySize, valuesMin, valuesMax);
		Array* testArray = new Array(dataArray, arraySize);

		type elementToAdd = valuesMin + (bigNumberDist(gen) % (valuesMax - valuesMin));
		int randomPosition = bigNumberDist(gen) % arraySize;

		timer.startTimer();
		testArray->addAt(elementToAdd, randomPosition);
		timer.endTimer();

		delete testArray;
		delete dataArray;
	}
	timer.divideMemory(iterations);
	if (fileOutput)
		std::cout << arraySize << ";" << timer.timeMicroSecondsMemory() << std::endl;
	else
		std::cout << "Sredni czas (" << iterations << " iteracji) dodawania elementu na losowa pozycje " << arraySize << " elementowej tablicy [" << valuesMin << ", " << valuesMax << "): " << timer.timeMicroSecondsMemory() << " uS" << std::endl;
}

void PerformanceTester::deleteElementFromTheFrontOfArray(int arraySize, type valuesMin, type valuesMax, int iterations) {

	timer.resetMemory();
	for (int i = 0; i < iterations; i++) {
		type* dataArray = generateTestData(arraySize, valuesMin, valuesMax);
		Array* testArray = new Array(dataArray, arraySize);

		timer.startTimer();
		testArray->deleteFront();
		timer.endTimer();

		delete testArray;
		delete dataArray;
	}
	timer.divideMemory(iterations);
	if (fileOutput)
		std::cout << arraySize << ";" << timer.timeMicroSecondsMemory() << std::endl;
	else
		std::cout << "Sredni czas (" << iterations << " iteracji) usuwania elementu z poczatku " << arraySize << " elementowej tablicy [" << valuesMin << ", " << valuesMax << "): " << timer.timeMicroSecondsMemory() << " uS" << std::endl;
}

void PerformanceTester::deleteElementFromTheEndOfArray(int arraySize, type valuesMin, type valuesMax, int iterations) {

	timer.resetMemory();
	for (int i = 0; i < iterations; i++) {
		type* dataArray = generateTestData(arraySize, valuesMin, valuesMax);
		Array* testArray = new Array(dataArray, arraySize);

		timer.startTimer();
		testArray->deleteEnd();
		timer.endTimer();

		delete testArray;
		delete dataArray;
	}
	timer.divideMemory(iterations);
	if (fileOutput)
		std::cout << arraySize << ";" << timer.timeMicroSecondsMemory() << std::endl;
	else
		std::cout << "Sredni czas (" << iterations << " iteracji) usuwania elementu z konca " << arraySize << " elementowej tablicy [" << valuesMin << ", " << valuesMax << "): " << timer.timeMicroSecondsMemory() << " uS" << std::endl;
}

void PerformanceTester::deleteElementFromTheRandomOfArray(int arraySize, type valuesMin, type valuesMax, int iterations){

	timer.resetMemory();
	for (int i = 0; i < iterations; i++) {
		type* dataArray = generateTestData(arraySize, valuesMin, valuesMax);
		Array* testArray = new Array(dataArray, arraySize);

		type elementToAdd = valuesMin + (bigNumberDist(gen) % (valuesMax - valuesMin));
		int randomPosition = bigNumberDist(gen) % arraySize;

		timer.startTimer();
		testArray->deleteAt(randomPosition);
		timer.endTimer();

		delete testArray;
		delete dataArray;
	}
	timer.divideMemory(iterations);
	if (fileOutput)
		std::cout << arraySize << ";" << timer.timeMicroSecondsMemory() << std::endl;
	else
		std::cout << "Sredni czas (" << iterations << " iteracji) usuwania elementu z losowej pozycji " << arraySize << " elementowej tablicy [" << valuesMin << ", " << valuesMax << "): " << timer.timeMicroSecondsMemory() << " uS" << std::endl;
}

void PerformanceTester::findElementInArray(int arraySize, type valuesMin, int iterations) {
	
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
		Array* testArray = new Array(dataArray, arraySize);


		type randomElement = dataVec[bigNumberDist(gen) % arraySize];

		timer.startTimer();
		int result = testArray->find(randomElement);
		timer.endTimer();

		delete testArray;
		delete dataArray;
	}
	timer.divideMemory(iterations);
	if (fileOutput)
		std::cout << arraySize << ";" << timer.timeMicroSecondsMemory() << std::endl;
	else
		std::cout << "Sredni czas (" << iterations << " iteracji) znajdywania elementu " << arraySize << " elementowej tablicy [" << valuesMin << ", " << valuesMin + arraySize << "): " << timer.timeMicroSecondsMemory() << " uS" << std::endl;

}

