#include "day14.hpp"

int main()
{
	std::vector<std::pair<Point, Point>>	robots = parseInput("input.txt");

	silver(robots);
	gold(robots);
}

