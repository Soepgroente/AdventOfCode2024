#include "day15.hpp"

/*	takes coordinates of leftmost box and a direction	*/

std::vector<std::vector<char>>	tg;

static void	insertBox(int x, int y, int dir)
{
	tg[x][y] = BOXL;
	tg[x][y + 1] = BOXR;
	tg[x - dir][y] = EMPTY;
	tg[x - dir][y + 1] = EMPTY;
}

/* static bool	insertBox(int x, int y, int dir)
{
	if (tg[x][y] == WALL || tg[x][y + 1] == WALL)
		return (false);
	if (tg[x + dir][y - 1] == BOXL)
		return (insertBox(x + dir, y - 1, dir));
	if (tg[x + dir][y] == BOXL)
		return (insertBox(x + dir, y, dir));
	if (tg[x + dir][y + 1] == BOXL)
		return (insertBox(x + dir, y + 1, dir));
	tg[x][y] = BOXL;
	tg[x][y + 1] = BOXR;
	return (true);
} */

static bool	insertBoxes(int x, int y, int dir)
{
	if (tg[x][y] == WALL || tg[x][y + 1] == WALL)
	{
		// std::cout << "Oh oh... x: " << x + dir << " y: " << y << " tiles: " << tg[x + dir][y] << tg[x + dir][y + 1] << std::endl;
		// printGrid(tg);
		return (false);
	}
	if (tg[x][y] == EMPTY && tg[x][y + 1] == EMPTY)
		return (true);
	if (tg[x][y - 1] == BOXL)
	{
		if (insertBoxes(x + dir, y - 1, dir) == false)
			return (false);
		insertBox(x + dir, y - 1, dir);
	}
	if (tg[x][y + 1] == BOXL)
	{
		if (insertBoxes(x + dir, y + 1, dir) == false)
			return (false);
		insertBox(x + dir, y + 1, dir);
	}
	if (tg[x][y] == BOXL)
	{
		if (insertBoxes(x + dir, y, dir) == false)
			return (false);
		insertBox(x + dir, y, dir);
		return (true);
	}
	return (true);
}

static void	up(std::vector<std::vector<char>>& grid, Point& r)
{
	tg = grid;
	int x = r.x - 1, y = r.y;

	if (grid[x][y] == WALL)
		return ;
	if (grid[x][y] == BOXR)
		y--;
	if (grid[x][y] == EMPTY)
		r.x--;
	else if (insertBoxes(x, y, -1) == true)
	{
		grid = tg;
		grid[x][y] = EMPTY;
		grid[x][y + 1] = EMPTY;
		r.x--;
	}
}

static void	down(std::vector<std::vector<char>>& grid, Point& r)
{
	tg = grid;
	int x = r.x + 1, y = r.y;

	if (grid[x][y] == WALL)
		return ;
	if (grid[x][y] == BOXR)
		y--;
	if (grid[x][y] == EMPTY)
		r.x++;
	else if (insertBoxes(x, y, 1) == true)
	{
		grid = tg;
		grid[x][y] = EMPTY;
		grid[x][y + 1] = EMPTY;
		r.x++;
	}
}

static void	left(std::vector<std::vector<char>>& grid, Point& r)
{
	int x = r.x, y = r.y - 1;
	int i = 0;

	if (grid[x][y] == WALL)
		return ;
	if (grid[x][y] == BOXR)
	{
		while (grid[x][y + i] == BOXR)
		{
			i -= 2;
			if (grid[x][y + i] == WALL)
				return ;
		}
		while (i < 0)
		{
			grid[x][y + i] = BOXL;
			grid[x][y + i + 1] = BOXR;
			i += 2;
		}
	}
	r.y--;
}

static void	right(std::vector<std::vector<char>>& grid, Point& r)
{
	int x = r.x, y = r.y + 1;
	int i = 0;

	if (grid[x][y] == WALL)
		return ;
	if (grid[x][y] == BOXL)
	{
		while (grid[x][y + i] == BOXL)
		{
			i += 2;
			if (grid[x][y + i] == WALL)
				return ;
		}
		while (i > 0)
		{
			grid[x][y + i - 1] = BOXL;
			grid[x][y + i] = BOXR;
			i -= 2;
		}
	}
	r.y++;
}

static void	moveRobot(std::vector<std::vector<char>>& grid, std::vector<int>& directions, Point& robot)
{
	void	(*move[4])(std::vector<std::vector<char>>&, Point&) = {&left, &up, &right, &down};

	for (int& it : directions)
	{
		grid[robot.x][robot.y] = EMPTY;
		move[it](grid, robot);
		grid[robot.x][robot.y] = ROBOT;
	}
}

static void	morphGrid(std::vector<std::vector<char>>& grid)
{
	for (size_t x = 0; x < grid.size(); x++)
	{
		for (size_t y = 0; y < grid[x].size(); y += 2)
		{
			if (grid[x][y] == BOX)
			{
				grid[x][y] = BOXR;
				grid[x].insert(grid[x].begin() + y, BOXL);
			}
			else
				grid[x].insert(grid[x].begin() + y, grid[x][y]);
		}
	}
}

void	gold(std::vector<std::vector<char>> grid, std::vector<int>& directions, Point robot)
{
	morphGrid(grid);
	moveRobot(grid, directions, robot);
	printGrid(grid);
	std::cout << "Gold: " << getTotal(grid, '[') << std::endl;
}