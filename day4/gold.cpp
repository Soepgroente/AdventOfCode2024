#include "day4.hpp"

static bool	positiveDiagonal(int x, int y)
{
	if ((g[x - 1][y + 1] == 'M' && g[x + 1][y - 1] == 'S') ||
		(g[x - 1][y + 1] == 'S' && g[x + 1][y - 1] == 'M'))
	{
		return (true);
	}
	return (false);
}

static bool	negativeDiagonal(int x, int y)
{
	if ((g[x - 1][y - 1] == 'M' && g[x + 1][y + 1] == 'S') ||
		(g[x - 1][y - 1] == 'S' && g[x + 1][y + 1] == 'M'))
	{
		return (true);
	}
	return (false);
}

static bool	verifyXmas(int x, int y)
{
	if (positiveDiagonal(x, y) == true && negativeDiagonal(x, y) == true)
		return (true);
	return (false);
}

void	gold()
{
	uint64_t	count = 0;

	for (int x = 4; x < 144; x++)
	{
		for (int y = 4; y < 144; y++)
		{
			if (g[x][y] == 'A')
				count += verifyXmas(x, y);
		}
	}
	std::cout << "Gold: " << count << std::endl;
}