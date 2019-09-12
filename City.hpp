//
// Created by Vladyslav USLYSTYI on 2019-09-12.
//

#ifndef CITIES_CITY_HPP
#define CITIES_CITY_HPP

#include <string>

class City
{

private:

	std::string				name;
	char 					start;
	char 					end;
	unsigned int			index;
	unsigned int 			len;

	static unsigned int		cityCounter;

	unsigned int letterCounter(std::string const &str);

public:

	City(std::string const &cityName);

	bool		isCompatible(City const &city);

	int 		getDistance(City const &city);
};


#endif //CITIES_CITY_HPP
