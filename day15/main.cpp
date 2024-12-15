#include "day15.hpp"

static Point	findRobot(std::vector<std::vector<char>>& grid)
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
	std::vector<std::vector<char>>	grid = parseInput("input.txt");
	std::vector<int>	directions = parseDirs("movements.txt");
	Point	start = findRobot(grid);

	// silver(grid, directions, start);
	grid[start.x][start.y] = EMPTY;
	start.y *= 2;
	gold(grid, directions, start);
}