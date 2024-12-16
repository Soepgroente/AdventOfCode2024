#include "day16.hpp"

Point finish;
Point dirs[4];

void	markRoute(std::vector<std::vector<int>>& maze, Point loc, int dir, int pts)
{
	if (loc == finish || maze[loc.x][loc.y] == WALL || maze[loc.x][loc.y] == -2)
		return ;
	Point tmp = loc + dirs[dir];
	if (maze[tmp.x][tmp.y] == pts + 1 || maze[tmp.x][tmp.y] == pts + 1001)
	{
		pts += maze[tmp.x][tmp.y];
		maze[tmp.x][tmp.y] = -2;
		markRoute(maze, tmp, dir, pts);
	}
	turnLeft(dir);
	tmp = loc + dirs[dir];
	markRoute(maze, tmp, dir, pts);
	turnRight(dir);
	turnRight(dir);
	tmp = loc + dirs[dir];
	markRoute(maze, tmp, dir, pts);
}

void	gold(std::vector<std::vector<int>>& maze, Point s, Point e)
{
	int count = 0;
	finish = e;

	dirs[LEFT] = Point(0, -1);
	dirs[UP] = Point(-1, 0);
	dirs[RIGHT] = Point(0, 1);
	dirs[DOWN] = Point(1, 0);
	printGrid(maze);
	markRoute(maze, s, UP, 0);
	for (size_t x = 0; x < maze.size(); x++)
	{
		for (size_t y = 0; y < maze[x].size(); y++)
		{
			if (maze[x][y] == -2)
				count++;
		}
	}
	printGrid(maze);
	std::cout << "Gold: " << count << std::endl;
}