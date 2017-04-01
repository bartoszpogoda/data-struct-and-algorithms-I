#include "FileReader.h"
#include "Type.h"
#include <fstream>

std::string FileReader::readArray(std::string filename, Array* &array) {

	std::ifstream file = std::ifstream("data/" + filename);

	if (array == nullptr) {
		array = new Array();
	}

	int size;
	type val;

	if (file.is_open())
	{
		file >> size;
		if (file.fail())
			return "Blad odczytu pliku - wielkosc danych";
		else
			for (int i = 0; i < size; i++)
			{
				file >> val;
				if (file.fail())
				{
					return "Blad odczytu pliku - dane";
					break;
				}
				else
					array->addEnd(val);
			}
		file.close();
	}
	else
		return "Blad odczytu pliku - otwarcie pliku";

	return "Sukces! Dane wczytane.";

}

std::string FileReader::readBDList(std::string filename, BDList *& bdList) {
	std::ifstream file = std::ifstream("data/" + filename);

	if (bdList == nullptr) {
		bdList = new BDList();
	}

	int size;
	type val;

	if (file.is_open())
	{
		file >> size;
		if (file.fail())
			return "Blad odczytu pliku - wielkosc danych";
		else
			for (int i = 0; i < size; i++)
			{
				file >> val;
				if (file.fail())
				{
					return "Blad odczytu pliku - dane";
					break;
				}
				else
					bdList->addEnd(val);
			}
		file.close();
	}
	else
		return "Blad odczytu pliku - otwarcie pliku";

	return "Sukces! Dane wczytane.";
}


std::string FileReader::readHeap(std::string filename, Heap *& heap) {
	std::ifstream file = std::ifstream("data/" + filename);

	if (heap == nullptr) {
		heap = new Heap();
	}

	int size;
	type val;

	if (file.is_open())
	{
		file >> size;
		if (file.fail())
			return "Blad odczytu pliku - wielkosc danych";
		else
			for (int i = 0; i < size; i++)
			{
				file >> val;
				if (file.fail())
				{
					return "Blad odczytu pliku - dane";
					break;
				}
				else
					heap->add(val);
			}
		file.close();
	}
	else
		return "Blad odczytu pliku - otwarcie pliku";

	return "Sukces! Dane wczytane.";
}

std::string FileReader::readBSTree(std::string filename, BSTree *& brTree) {

	std::ifstream file = std::ifstream("data/" + filename);

	if (brTree == nullptr) {
		brTree = new BSTree();
	}

	int size;
	type val;

	if (file.is_open())
	{
		file >> size;
		if (file.fail())
			return "Blad odczytu pliku - wielkosc danych";
		else
			for (int i = 0; i < size; i++)
			{
				file >> val;
				if (file.fail())
				{
					return "Blad odczytu pliku - dane";
					break;
				}
				else
					brTree->add(val);
			}
		file.close();
	}
	else
		return "Blad odczytu pliku - otwarcie pliku";

	return "Sukces! Dane wczytane.";
}
