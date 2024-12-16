#include "day16.hpp"

Point directions[4];
Point start;
Point end;

static std::vector<std::vector<int>>	copyInput(std::vector<std::vector<char>>& in)
{
	std::vector<std::vector<int>>	maze;

	maze.resize(in.size());
	for (size_t x = 0; x < in.size(); x++)
	{
		for (size_t y = 0; y < in[x].size(); y++)
		{
			if (in[x][y] == '#')
				maze[x].push_back(-1);
			else if (in[x][y] == '.' || in[x][y] == 'E')
				maze[x].push_back(INT32_MAX);
			else if(in[x][y] == 'S')
				maze[x].push_back(0);			
		}
	}
	return (maze);
}

static void	findPath(std::vector<std::vector<int>>& maze, Point loc, int dir, int total)
{
	if (maze[loc.x][loc.y] == WALL)
	{
		return ;
	}
	if (total < maze[loc.x][loc.y])
	{
		maze[loc.x][loc.y] = total;
	}
	if (total > maze[loc.x][loc.y])
	{
		return ;
	}
	if (loc == end)
		return ;
	findPath(maze, (loc + directions[dir]), dir, total + 1);
	turnLeft(dir);
	findPath(maze, (loc + directions[dir]), dir, total + 1001);
	turnRight(dir);
	turnRight(dir);
	findPath(maze, (loc + directions[dir]), dir, total + 1001);
}

std::vector<std::vector<int>>	silver(std::vector<std::vector<char>> in, Point s, Point e)
{
	std::vector<std::vector<int>>	maze = copyInput(in);

	start = s;
	end = e;
	directions[LEFT] = Point(0, -1);
	directions[UP] = Point(-1, 0);
	directions[RIGHT] = Point(0, 1);
	directions[DOWN] = Point(1, 0);
	findPath(maze, start, RIGHT, 0);
	std::cout << "Silver: " << maze[e.x][e.y] << std::endl;
	return (maze);
}
