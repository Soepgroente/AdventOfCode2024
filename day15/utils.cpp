#include "day15.hpp"

void	printGrid(std::vector<std::vector<char>>& grid)
{
	for (std::vector<char>& it : grid)
	{
		printArray(it, 0);
	}
}

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
