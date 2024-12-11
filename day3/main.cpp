#include "day3.hpp"

int main()
{
	std::vector<std::string>	input = parseInput("input.txt");
	std::vector<std::string>	goldInput = parseInput("goldinput.txt");

	silver(input);
	gold(goldInput);
}