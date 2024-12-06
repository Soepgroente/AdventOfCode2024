#include "day6.hpp"

int a;
int b;

static bool	left()
{
	while (b >= 0)
	{
		if (g[a][b] == '#')
		{
			b++;
			return (false);
		}
		g[a][b] = 'X';
		b--;
	}
	return (true);
}

static bool	right()
{
	while (b < YSIZE)
	{
		if (g[a][b] == '#')
		{
			b--;
			return (false);
		}
		g[a][b] = 'X';
		b++;
	}
	return (true);
}

static bool	down()
{
	while (a < XSIZE)
	{
		if (g[a][b] == '#')
		{
			a--;
			return (false);
		}
		g[a][b] = 'X';
		a++;
	}
	return (true);
}

static bool	up()
{
	while (a >= 0)
	{
		if (g[a][b] == '#')
		{
			a++;
			return (false);
		}
		g[a][b] = 'X';
		a--;
	}
	return (true);
}

void	silver(int xStart, int yStart)
{
	int i = 0;
	bool (*f[4])() = {&up, &right, &down, &left};

	a = xStart;
	b = yStart;

	while (f[i]() == false)
	{
		i++;
		if (i == 4)
			i = 0;
	}
	uint64_t	count = 0;

	for (size_t x = 0; x < XSIZE; x++)
	{
		for (size_t y = 0; y < YSIZE; y++)
		{
			if (g[x][y] == 'X')
				count++;
		}
	}
	std::cout << "Silver: " << count << std::endl;
}