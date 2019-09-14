#include <string>
#include <vector>
#include <map>
#include <deque>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

vector<string> combine_cities(vector<string> available_cities);
vector<string> read_available_cities();
int write_to_file(vector<string> cities_list);

int	getMaxIndex(char lastLetter, map<char, deque<string > >	&letter);
char getLetterForStart(map<char, deque<string > > &letter, vector<string> &cities);


int main() 
{
  vector<string> available_cities = read_available_cities();

  vector<string> cities_list = combine_cities(available_cities);

  return write_to_file(cities_list);
}

vector<string> combine_cities(vector<string> available_cities) {

	map<char, deque<string > >	letter;
	char						lastLetter;
    int                         maxIndex;
    string                      tmpCity;

	for(vector<string>::iterator c = available_cities.begin(); c != available_cities.end(); c++) {
        (*c)[0] = tolower((*c)[0]);
        letter[(*c).front()].push_back(*c);
    }

	lastLetter = getLetterForStart(letter, available_cities);

	available_cities.clear();

	while (letter[lastLetter].size())
	{
		maxIndex = getMaxIndex(lastLetter, letter);
        tmpCity = letter[lastLetter][maxIndex];

        tmpCity[0] = toupper(tmpCity[0]);
		available_cities.push_back(tmpCity);
		letter[lastLetter].erase(letter[lastLetter].begin() + maxIndex);
		lastLetter = tmpCity.back();
	}
	return available_cities;
}

vector<string> read_available_cities() {
  string line;
  ifstream input_file ("input.txt");
  vector<string> available_cities;  
  while ( getline (input_file,line) )
  {
    available_cities.push_back(line);
  }
  input_file.close();

  return available_cities;
}

int write_to_file(vector<string> cities_list) {
  ofstream output_file("./output.txt");
  ostream_iterator<string> output_iterator(output_file, "\n");
  copy(cities_list.begin(), cities_list.end(), output_iterator);

  return 0;
}

int	getMaxIndex(char lastLetter, map<char, deque<string > > &letter)
{
	int 			i = 0;
	int 			maxIndex = 0;
	unsigned int 	maxSize = 0;
	unsigned int 	maxLen = 0;

    for(deque<string>::iterator c = letter[lastLetter].begin(); c != letter[lastLetter].end(); c++)
	{
		if (letter[(*c).back()].size() > maxSize)
		{
			maxSize = letter[(*c).back()].size();
			maxLen = (*c).size();
			maxIndex = i;
		}
		else if (letter[(*c).back()].size() == maxSize && (*c).size() > maxLen)
		{
			maxIndex = i;
			maxLen = (*c).size();
		}
		i++;
	}
	return maxIndex;
}

char getLetterForStart(map<char, deque<string > > &letter, vector<string> &cities)
{
	unsigned int 	maxEndLetter = 0;
	char			lastLetter = 'a';

    for(vector<string>::iterator c = cities.begin(); c != cities.end(); c++)
		if (letter[(*c).back()].size() > maxEndLetter)
		{
			maxEndLetter = letter[(*c).back()].size();
			lastLetter = (*c).back();
		}
	return (lastLetter);
}