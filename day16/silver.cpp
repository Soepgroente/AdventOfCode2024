#include "day16.hpp"

Point directions[4];

static long	findPath(std::vector<std::vector<char>>& maze, Point loc, Point dir, size_t count)
{
	if ()
	if (maze[loc.x + dir.x][loc.y + dir.y] != WALL)
	{
		count++;

	}
}

void	silver(std::vector<std::vector<char>> maze, Point start)
{
	directions[0] = Point(0, -1);
	directions[1] = Point(-1, 0);
	directions[2] = Point(0, 1);
	directions[3] = Point(1, 0);
	std::cout << "Silver: " << findPath(maze, start, directions[RIGHT], 0) << std::endl;
}