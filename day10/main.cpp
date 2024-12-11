#include "day10.hpp"

int main()
{
	std::vector<std::vector<int>>	map = parseInput("input.txt");

	silver(map);
	gold(map);
}