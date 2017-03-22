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
					array->addElementEnd(val);
			}
		file.close();
	}
	else
		return "Blad odczytu pliku - otwarcie pliku";

	return "Sukces! Dane wczytane.";

}
