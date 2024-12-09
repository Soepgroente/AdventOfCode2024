#include "day8.hpp"

int main()
{
	std::vector<std::vector<char>>	grid = parseInput("input.txt");

	silver(grid);
	gold(grid);
}