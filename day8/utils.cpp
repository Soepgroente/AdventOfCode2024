#include "day8.hpp"

std::vector<Point>	getLocations(std::vector<std::vector<char>>& input, char c)
{
	std::vector<Point>	locations;

	for (size_t x = 0; x < input.size(); x++)
	{
		for (size_t y = 0; y < input[x].size(); y++)
		{
			if (input[x][y] == c)
			{
				locations.emplace_back(Point{(int)x, (int)y});
			}
		}
	}
	return (locations);
}