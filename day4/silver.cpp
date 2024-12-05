#include "day4.hpp"

static uint64_t	checkDiagonal(int x, int y)
{
	uint64_t	count = 0;

	if (g[x + 1][y + 1] == 'M' && g[x + 2][y + 2] == 'A' && g[x + 3][y + 3] == 'S')
		count++;
	if (g[x - 1][y - 1] == 'M' && g[x - 2][y - 2] == 'A' && g[x - 3][y - 3] == 'S')
		count++;
	if (g[x + 1][y - 1] == 'M' && g[x + 2][y - 2] == 'A' && g[x + 3][y - 3] == 'S')
		count++;
	if (g[x - 1][y + 1] == 'M' && g[x - 2][y + 2] == 'A' && g[x - 3][y + 3] == 'S')
		count++;
	return (count);
}

static uint64_t	checkVertical(int x, int y)
{
	uint64_t	count = 0;

	if (g[x + 1][y] == 'M' && g[x + 2][y] == 'A' && g[x + 3][y] == 'S')
		count++;
	if (g[x - 1][y] == 'M' && g[x - 2][y] == 'A' && g[x - 3][y] == 'S')
		count++;
	return (count);
}

static uint64_t	checkHorizontal(int x, int y)
{
	uint64_t	count = 0;

	if (g[x][y + 1] == 'M' && g[x][y + 2] == 'A' && g[x][y + 3] == 'S')
		count++;
	if (g[x][y - 1] == 'M' && g[x][y - 2] == 'A' && g[x][y - 3] == 'S')
		count++;
	return (count);
}

static uint64_t	verifyXmas(int x, int y)
{
	uint64_t	count = 0;

	count += checkHorizontal(x, y);
	count += checkVertical(x, y);
	count += checkDiagonal(x, y);
	return (count);
}

void	silver()
{
	uint64_t	count = 0;

	for (int x = 4; x < 144; x++)
	{
		for (int y = 4; y < 144; y++)
		{
			if (g[x][y] == 'X')
				count += verifyXmas(x, y);
		}
	}
	std::cout << "Silver: " << count << std::endl;
}