#include "PerformanceTester.h"

type* PerformanceTester::generateTestData(int size, type valuesMin, type valuesMax) {
	type* dataArray = new type[size];

	for (int j = 0; j < size; j++)
		dataArray[j] = valuesMin + (bigNumberDist(gen) % (valuesMax - valuesMin));

	return dataArray;
}