//
// Created by Vladyslav USLYSTYI on 2019-09-12.
//

#include "City.hpp"

City::City(std::string const &cityName)
{
	name = cityName;
	start = tolower(name.front());
	end = tolower(name.back());
	index = cityCounter++;
	len = letterCounter(name);
}

unsigned int City::letterCounter(std::string const &str)
{
	int	counter = 0;

	for (char i : str)
	{
		if (isalpha(i))
			counter++;
	}

	return counter;
}

bool City::isCompatible(City const &city)
{
	return this != &city && this->end == city.start;
}

int City::getDistance(City const &city)
{
	if (this == &city)
		return (0);
	else if (this->end == city.start)
		return (-(this->len + city.len));
	else
		return (INT32_MAX);
}

unsigned int City::cityCounter = 0;