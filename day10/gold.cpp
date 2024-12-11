#include "day10.hpp"

std::vector<Point>	locations;

static bool	goDown(std::vector<std::vector<int>>& map, int x, int y, int n)
{
	if ((size_t)x < map.size() - 1 && map[x + 1][y] == n + 1)
		return (true);
	return (false);
}

static bool	goUp(std::vector<std::vector<int>>& map, int x, int y, int n)
{
	if (x > 0 && map[x - 1][y] == n + 1)
		return (true);
	return (false);
}

static bool	goRight(std::vector<std::vector<int>>& map, int x, int y, int n)
{
	if ((size_t)y < map[x].size() - 1 && map[x][y + 1] == n + 1)
		return (true);
	return (false);
}

static bool	goLeft(std::vector<std::vector<int>>& map, int x, int y, int n)
{
	if (y > 0 && map[x][y - 1] == n + 1)
		return (true);
	return (false);
}

static void	addTrails(std::vector<std::vector<int>>& map, int x, int y, int n)
{
	if (n < 9)
	{
		if (goLeft(map, x, y, n) == true)
		{
			addTrails(map, x, y - 1, n + 1);
		}
		if (goRight(map, x, y, n) == true)
		{
			addTrails(map, x, y + 1, n + 1);
		}
		if (goUp(map, x, y, n) == true)
		{
			addTrails(map, x - 1, y, n + 1);
		}
		if (goDown(map, x, y,  n) == true)
		{
			addTrails(map, x + 1, y, n + 1);
		}
	}
	if (map[x][y] == 9)
		locations.push_back(Point{x, y});
}

void	gold(std::vector<std::vector<int>>& map)
{
	size_t	count = 0;

	for (size_t x = 0; x < map.size(); x++)
	{
		for (size_t y = 0; y < map[x].size(); y++)
		{
			if (map[x][y] == 0)
			{
				addTrails(map, x, y, 0);
				count += locations.size();
				locations.clear();
			}
		}
	}
	std::cout << "Gold: " << count << std::endl;
}