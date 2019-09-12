#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include "City.hpp"
#include "Floyd.hpp"

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

	// Allocate memory for direction matrix
	int **directionMatrix = new int*[cities.size()];
	for (int i = 0; i < cities.size(); i++)
		directionMatrix[i] = new int[cities.size()];

	row = 0;
	while (row < cities.size())
	{
		col = 0;
		while (col < cities.size())
		{
			// filling directionMatrix
			if (row == col)
				directionMatrix[row][col] = 0;
			else
				directionMatrix[row][col] = col + 1;

			// filling incidentMatrix
			incidentMatrix[row][col] = cities[row].getDistance(cities[col]);

			col++;
		}
		row++;
	}

	Floyd	floyd(incidentMatrix, directionMatrix, cities.size());

	floyd.computeLargestWays();

	for (row = 0; row < cities.size(); row++)
	{
		for (col = 0; col < cities.size(); col++)
			std::cout << std::setw(3) << directionMatrix[row][col] << " ";
		std::cout << std::endl;
	}

	return 0;
}