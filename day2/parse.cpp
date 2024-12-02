#include "day2.hpp"

std::vector<std::string>	parseInput()
{
	std::vector<std::string>	input;
	std::ifstream				file;
	std::string					tmp;

	file.open("input.txt");
	if (file.is_open() == false)
	{
		std::cerr << "Couldn't open input file" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	while (file.eof() == false)
	{
		std::getline(file, tmp, '\n');
		input.emplace_back(std::move(tmp));
	}
	return (input);
}