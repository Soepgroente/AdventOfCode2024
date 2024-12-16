#include "day16.hpp"

static Point	findPoint(std::vector<std::vector<char>>& grid, char toFind)
{
	for (size_t x = 0; x < grid.size(); x++)
	{
		for (size_t y = 0; y < grid[x].size(); y++)
		{
			if (grid[x][y] == toFind)
				return (Point(x, y));
		}
	}
	return (Point(-1, -1));
}

int main()
{
	std::vector<std::vector<char>>	maze = parseInput("input.txt");
	Point	start = findPoint(maze, 'S');
	Point	end = findPoint(maze, 'E');

	std::vector<std::vector<int>> map = silver(maze, start, end);
	gold(map, start, end);
}