#include "day8.hpp"

std::vector<std::vector<char>>	map;

static bool isInBounds(const std::vector<std::vector<char>>& input, const Point& point)
{
	if (point.x < 0 || point.y < 0)
		return (false);
	if ((size_t)point.x < input.size() && (size_t)point.y < input[point.x].size())
		return (true);
	return (false);
}

static void	markFrequencies(const std::vector<std::vector<char>>& input, const Point& a, const Point& b)
{
	Point	ab = b - a;
	Point	c = a;

	while (isInBounds(input, c) == true)
	{
		map[c.x][c.y] = '#';
		c = c + ab;
	}
	c = a;
	while (isInBounds(input, c) == true)
	{
		map[c.x][c.y] = '#';
		c = c - ab;
	}
}

static size_t	castFrequencies(std::vector<std::vector<char>>& input, char c)
{
	std::vector<Point>	locations = getLocations(input, c);
	size_t	count = 0;

	if (locations.size() == 0)
		return (0);
	for (size_t x = 0; x < locations.size(); x++)
	{
		for (size_t y = x + 1; y < locations.size(); y++)
		{
			markFrequencies(input, locations[x], locations[y]);
		}
	}
	return (count);
}

void	gold(std::vector<std::vector<char>>& input)
{
	map = input;
	size_t	count = 0;

	for (size_t i = 0; i < 127; i++)
	{
		if (!(std::isalnum(static_cast<int> (i)) == false))
		{
			castFrequencies(input, static_cast<char> (i));
		}
	}
	for (size_t x = 0; x < map.size(); x++)
	{
		for (size_t y = 0; y < map[x].size(); y++)
		{
			if (map[x][y] == '#')
				count++;
		}
	}
	for (size_t i = 0; i < map.size(); i++)
	{
		printArray(map[i], '\0');
	}
	std::cout << "Gold: " << count << std::endl;
}