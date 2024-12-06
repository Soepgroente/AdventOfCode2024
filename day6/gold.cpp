#include "day6.hpp"

int x, y;
char grid[XSIZE][YSIZE];

static int	left()
{
	while (y >= 0)
	{
		if (grid[x][y] == 'L')
			return (1);
		if (grid[x][y] == '#')
		{
			y++;
			return (0);
		}
		grid[x][y] = 'L';
		y--;
	}
	return (-1);
}

static int	right()
{
	while (y < YSIZE)
	{
		if (grid[x][y] == 'R')
			return (1);
		if (grid[x][y] == '#')
		{
			y--;
			return (0);
		}
		grid[x][y] = 'R';
		y++;
	}
	return (-1);
}

static int	down()
{
	while (x < XSIZE)
	{
		if (grid[x][y] == 'D')
			return (1);
		if (grid[x][y] == '#')
		{
			x--;
			return (0);
		}
		grid[x][y] = 'D';
		x++;
	}
	return (-1);
}

static int	up()
{
	while (x >= 0)
	{
		if (grid[x][y] == 'U')
			return (1);
		if (grid[x][y] == '#')
		{
			x++;
			return (0);
		}
		grid[x][y] = 'U';
		x--;
	}
	return (-1);
}

static bool	tryInfiniteLoop(int xPos, int yPos)
{
	int (*f[4])() = {&up, &right, &down, &left};
	int i = 0;
	int tmp;
	int counter = 0;

	for (int x2 = 0; x2 < XSIZE; x2++)
	{
		for (int y2 = 0; y2 < YSIZE; y2++)
		{
			grid[x2][y2] = g[x2][y2];
		}
	}
	x = xPos;
	y = yPos;

	while (1)
	{
		if (counter > 10000000)
			return (true);
		tmp = f[i]();
		if (tmp == 1)
			return (true);
		if (tmp == -1)
			return (false);
		i++;
		counter++;
		if (i == 4)
			i = 0;
	}
}

void	gold(int xPos, int yPos)
{
	uint64_t	count = 0;

	for (int i = 0; i < XSIZE; i++)
	{
		for (int j = 0; j < YSIZE; j++)
		{
			if (g[i][j] != '#' && g[i][j] != '^')
			{
				g[i][j] = '#';
				count += tryInfiniteLoop(xPos, yPos);
				std::cout << "x: " << i << " y: " << j << " count: " << count << std::endl;
				g[i][j] = '.';
			}
		}
	}
	std::cout << "Gold: " << count << std::endl;
}
