//
// Created by Vladyslav USLYSTYI on 2019-09-12.
//

#include <iostream>
#include <iomanip>
#include "Floyd.hpp"
#define INF 2000000

Floyd::Floyd(int **iMatrix, int **dMatrix, int size)
{
	incidentMatrix = iMatrix;
	directionMatrix = dMatrix;
	this->size = size;
}

void Floyd::computeLargestWays()
{
	int		leader = 0;
	int		tmp;

	while (leader < size)
	{
		for (int row = 0; row < size; row++)
		{
			for (int col = 0; col < size; col++)
			{
//				int item = incidentMatrix[row][col];
//				int one = incidentMatrix[row][leader];
//				int two = incidentMatrix[leader][c];

				if (incidentMatrix[row][leader] == INF ||
					incidentMatrix[leader][col] == INF ||
					row == leader || col == leader || col == row)
					continue ;
				tmp = incidentMatrix[row][leader] + incidentMatrix[leader][col];
				if (incidentMatrix[row][col] > tmp)
				{
					incidentMatrix[row][col] = tmp;
					directionMatrix[row][col] = leader + 1;
				}
			}
		}
		leader++;


		for (int row = 0; row < size; row++)
		{
			for (int col = 0; col < size; col++)
				std::cout << std::setw(3) << incidentMatrix[row][col] << " ";
			std::cout << std::endl;
		}
		std::cout << std::endl;

	}
}