#include "day12.hpp"

int main(int argc, char** argv)
{
	std::vector<std::vector<char>>	grid;
	if (argc == 2)
		grid = parseInput(argv[1]);
	else
		grid = parseInput("testtest.txt");

	silver(grid);
	gold(grid);
}