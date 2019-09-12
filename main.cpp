#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include "City.hpp"

int main()
{
	std::vector<City>	cities;
	std::string			line;
	std::ifstream		file;

	int 				row;
	int 				col;


	file.open("some_cities.txt");
	while (getline(file, line))
		cities.emplace_back(line);

	// Allocate memory for incident matrix
	int **incidentMatrix = new int*[cities.size()];
	for (int i = 0; i < cities.size(); i++)
		incidentMatrix[i] = new int[cities.size()];

	row = 0;
	while (row < cities.size())
	{
		col = 0;
		while (col < cities.size())
		{
			incidentMatrix[row][col] = cities[row].getDistance(cities[col]);
			col++;
		}
		row++;
	}

	for (row = 0; row < cities.size(); row++)
	{
		for (col = 0; col < cities.size(); col++)
			std::cout << std::setw(3) << incidentMatrix[row][col] << " ";
		std::cout << std::endl;
	}

	return 0;
}