#include "day16.hpp"

size_t	getTotal(std::vector<std::vector<char>>& grid, char box)
{
	size_t	results = 0;

	for (size_t x = 0; x < grid.size(); x++)
	{
		for (size_t y = 0; y < grid[x].size(); y++)
		{
			if (grid[x][y] == box)
				results += x * 100 + y;
		}
	}
	return (results);
}

void	turnLeft(int& dir)
{
	if (dir == 0)
		dir = 3;
	else
		dir--;
}

void	turnRight(int& dir)
{
	dir = (dir + 1) % 4;
}