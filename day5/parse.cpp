#include "day5.hpp"

int	nextNumber(std::string& input)
{
	int	nxt = std::stoi(input);
	input.erase(0, 3);
	if (input == "\n")
		input.erase(0, 1);
	return (nxt);
}

void	parseInput()
{
	std::ifstream	file;
	std::string		input;

	file.open("input.txt");
	if (file.is_open() == false)
	{
		std::cerr << "Couldn't open input file" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	for (size_t i = 0; i < 1176; i++)
	{
		std::getline(file, input, '\n');
		pages.emplace_back().emplace_back(std::stoi(input));
		pages[i].emplace_back(std::stoi(input.substr(3)));
	}
	file.close();
	file.open("input2.txt");
	if (file.is_open() == false)
	{
		std::cerr << "Couldn't open input file" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	for (size_t i = 0; i < 214; i++)
	{
		std::getline(file, input, '\n');
		manual.emplace_back();
		while (input.size())
		{
			manual[i].emplace_back(nextNumber(input));
		}
	}
	file.close();
}