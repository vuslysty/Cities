//
// Created by Vladyslav USLYSTYI on 2019-09-12.
//

#ifndef CITIES_FLOYD_HPP
#define CITIES_FLOYD_HPP


class Floyd
{
	int **incidentMatrix;
	int **directionMatrix;
	int size;

public:
	Floyd(int **iMatrix, int **dMatrix, int size);

	void	computeLargestWays();
};


#endif //CITIES_FLOYD_HPP
