#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

#include <map>
#include <deque>


#include <string>

class City
{

public:

	std::string				name;
	char 					start;
	char 					end;
	unsigned int			index;
	unsigned int 			len;

	static unsigned int		cityCounter;

	unsigned int letterCounter(std::string const &str);


	City(std::string const &cityName);
};

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

unsigned int City::cityCounter = 0;



int main()
{
	std::vector<City>	cities;
	std::string			line;
	std::ifstream		file;


	file.open("cities.txt");
	while (getline(file, line))
		cities.emplace_back(line);

	std::map<char, std::deque<City>>	letter;
	std::deque<unsigned long>	chain;

	for(City const &c : cities)
		letter[c.start].push_front(c);

	srand(time(nullptr));

	char	lastLetter;
	int 	randIndex;

	randIndex = rand() % cities.size();

	City	tmpCity = cities[randIndex];

	int maxEndLetter = 0;

	lastLetter = 'a';

	for (City c : cities)
		if (letter[c.end].size() > maxEndLetter)
		{
			maxEndLetter = letter[c.end].size();
			lastLetter = c.end;
		}

	while (letter[lastLetter].size())
	{
		int i = 0;
		int maxIndex = 0;
		int maxSize = 0;
		int maxLen = 0;

		for (City city : letter[lastLetter])
		{
			if (letter[city.end].size() > maxSize)
			{
				maxSize = letter[city.end].size();
				maxLen = city.len;
				maxIndex = i;
			}
			else if (letter[city.end].size() == maxSize && city.len > maxLen)
			{
				maxIndex = i;
				maxLen = city.len;
			}

			i++;
		}

		tmpCity = letter[lastLetter][maxIndex];
		chain.push_back(tmpCity.index);
		letter[lastLetter].erase(letter[lastLetter].begin() + maxIndex);
		lastLetter = tmpCity.end;
		std::cout << cities.at(chain.back()).name << "->" << std::flush;
	}

	int size = 0;
	for (int i : chain)
		size += cities.at(i).len;

	std::cout << std::endl << "Score: " << size << std::endl;

	int maxLen = 0;
	for (City city : cities)
		maxLen += city.len;

	std::cout << "Max score: " << maxLen;


//	std::cout <<  letter['k'][24].name << letter['k'][25].name << std::endl;
//	letter['k'].erase(letter['k'].begin() + 25);
//	std::cout <<  letter['k'][24].name << letter['k'][25].name << std::endl;


//	for (cur=letter.begin();cur!=letter.end();cur++)
//	{
//		std::cout << (*cur).first << ": " << (*cur).second << std::endl;
//	}

//	// Allocate memory for incident matrix
//	int **incidentMatrix = new int*[cities.size()];
//	for (int i = 0; i < cities.size(); i++)
//		incidentMatrix[i] = new int[cities.size()];
//
//	row = 0;
//	while (row < cities.size())
//	{
//		col = 0;
//		while (col < cities.size())
//		{
//			// filling incidentMatrix
//			incidentMatrix[row][col] = cities[row].getDistance(cities[col]);
//
//			col++;
//		}
//		row++;
//	}

//	for (row = 0; row < cities.size(); row++)
//	{
//		for (col = 0; col < cities.size(); col++)
//			std::cout << std::setw(3) << directionMatrix[row][col] << " ";
//		std::cout << std::endl;
//	}

	return 0;
}