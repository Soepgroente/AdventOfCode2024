#include "day16.hpp"

static Point	findStart(std::vector<std::vector<char>>& grid)
{
	for (size_t x = 0; x < grid.size(); x++)
	{
		for (size_t y = 0; y < grid[x].size(); y++)
		{
			if (grid[x][y] == '@')
				return (Point(x, y));
		}
	}
	return (Point(-1, -1));
}

int main()
{
	std::vector<std::vector<char>>	maze = parseInput("input.txt");
	Point	start = findStart(maze);

	silver(maze, start);
	gold(maze, start);
}