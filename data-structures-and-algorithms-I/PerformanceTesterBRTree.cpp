#include "PerformanceTester.h"
#include "BRTree.h"
#include <time.h>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

void PerformanceTester::addElementToBRTree(int size, type valuesMin, type valuesMax, int iterations) {
	timer.resetMemory();
	for (int i = 0; i < iterations; i++) {
		BRTree* testBRTree = new BRTree();

		for (int j = 0; j < size; j++)
			testBRTree->add(valuesMin + (bigNumberDist(gen) % (valuesMax - valuesMin)));


		type elementToAdd = valuesMin + (bigNumberDist(gen) % (valuesMax - valuesMin));

		timer.startTimer();
		testBRTree->add(elementToAdd);
		timer.endTimer();

		delete testBRTree;
	}
	timer.divideMemory(iterations);
	if (fileOutput)
		std::cout << size << ";" << timer.timeMicroSecondsMemory() << std::endl;
	else
		std::cout << "Sredni czas (" << iterations << " iteracji) dodawania elementu do " << size << " elementowego BRTree [" << valuesMin << ", " << valuesMax << "): " << timer.timeMicroSecondsMemory() << " uS" << std::endl;

}

void PerformanceTester::findElementInBRTree(int arraySize, type valuesMin, int iterations) {
	std::vector<type> dataVec = std::vector<type>(arraySize);
	int n = valuesMin;
	std::generate(dataVec.begin(), dataVec.end(), [&n] {return n++; });
	auto engine = std::default_random_engine{};

	timer.resetMemory();
	for (int i = 0; i < iterations; i++) {
		BRTree* testBRTree = new BRTree();

		std::shuffle(dataVec.begin(), dataVec.end(), engine);
		for (int j = 0; j < arraySize; j++)
			testBRTree->add(dataVec[j]);

		type randomElement = dataVec[bigNumberDist(gen) % arraySize];

		timer.startTimer();
		testBRTree->find(randomElement);
		timer.endTimer();

		delete testBRTree;
	}
	timer.divideMemory(iterations);
	if (fileOutput)
		std::cout << arraySize << ";" << timer.timeMicroSecondsMemory() << std::endl;
	else
		std::cout << "Sredni czas (" << iterations << " iteracji) znajdywania elementu " << arraySize << " elementowego drzewa czerwono-czarnego [" << valuesMin << ", " << valuesMin + arraySize << "): " << timer.timeMicroSecondsMemory() << " uS" << std::endl;

}