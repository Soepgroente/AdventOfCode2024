#include "day11.hpp"

std::vector<size_t>	parseInput(std::string location)
{
	std::ifstream	file;
	std::string		tmp;
	std::vector<size_t>	input;

	file.open(location);
	if (file.is_open() == false)
	{
		std::cerr << "Couldn't open input file" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	while (file.eof() == false)
	{
		std::getline(file, tmp, '\n');
	}
	std::stringstream stream(tmp);

	while (stream >> tmp)
	{
		input.push_back(std::stoi(tmp));
	}
	return (input);
}