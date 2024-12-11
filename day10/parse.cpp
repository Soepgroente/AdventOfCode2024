#include "day10.hpp"

std::vector<std::vector<int>>	parseInput(std::string location)
{
	std::ifstream	file;
	std::string		tmp;
	std::vector<std::vector<int>>	input;

	file.open(location);
	if (file.is_open() == false)
	{
		std::cerr << "Couldn't open input file" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	size_t x = 0;
	while (file.eof() == false)
	{
		input.emplace_back();
		std::getline(file, tmp, '\n');
		for (size_t y = 0; y < tmp.size(); y++)
			input[x].emplace_back((int)tmp[y] - '0');
		x++;
	}
	return (input);
}