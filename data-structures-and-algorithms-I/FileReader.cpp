#include "FileReader.h"
#include "Type.h"
#include <fstream>

std::string FileReader::readArray(std::string filename, Array* &array) {

	std::ifstream file = std::ifstream("data/" + filename);

	delete array;
	array = nullptr;

	int size;
	type val;

	if (file.is_open())
	{
		file >> size;
		if (file.fail())
			return "Blad odczytu pliku - wielkosc danych";
		else {
			type* data = new type[size];
			for (int i = 0; i < size; i++)
			{
				file >> val;
				if (file.fail())
				{
					return "Blad odczytu pliku - dane";
					break;
				}
				else
					data[i] = val;
			}
			array = new Array(data, size);
		}
			
		file.close();
	}
	else
		return "Blad odczytu pliku - otwarcie pliku";

	return "Sukces! Dane wczytane.";

}

std::string FileReader::readBDList(std::string filename, BDList *& bdList) {
	std::ifstream file = std::ifstream("data/" + filename);

	delete bdList;
	bdList = nullptr;

	int size;
	type val;

	if (file.is_open())
	{
		file >> size;
		if (file.fail())
			return "Blad odczytu pliku - wielkosc danych";
		else {
			BDListNode** nodes = new BDListNode*[size];
			for (int i = 0; i < size; i++)
			{
				file >> val;
				if (file.fail())
				{
					for (int i = 0; i < size; i++)
						delete nodes[i];
					delete[] nodes;

					return "Blad odczytu pliku - dane";
					break;
				}
				else
					nodes[i] = new BDListNode(val);
			}
			bdList = new BDList(nodes, size);
			delete[] nodes;
		}
			
		file.close();
	}
	else
		return "Blad odczytu pliku - otwarcie pliku";

	return "Sukces! Dane wczytane.";
}


std::string FileReader::readHeap(std::string filename, Heap *& heap) {
	std::ifstream file = std::ifstream("data/" + filename);

	delete heap;
	heap = nullptr;
		

	int size;
	type val;

	if (file.is_open())
	{
		file >> size;
		if (file.fail())
			return "Blad odczytu pliku - wielkosc danych";
		else {
			type* data = new type[size];
			for (int i = 0; i < size; i++)
			{
				file >> val;
				if (file.fail())
				{
					return "Blad odczytu pliku - dane";
					break;
				}
				else
					data[i] = val;
			}
			heap = new Heap(data, size);
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
