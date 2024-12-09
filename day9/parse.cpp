#include "day9.hpp"

std::string	parseInput(std::string location)
{
	std::ifstream	file;
	std::string		input;

	file.open(location);
	if (file.is_open() == false)
	{
		std::cerr << "Couldn't open input file" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	std::getline(file, input, '\n');
	file.close();
	return (input);
}