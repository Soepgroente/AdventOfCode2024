#include "day8.hpp"

std::set<Point>	freQ;

static bool isInBounds(const std::vector<std::vector<char>>& input, const Point& point)
{
	if (point.x < 0 || point.y < 0)
		return (false);
	if ((size_t)point.x < input.size() && (size_t)point.y < input[point.x].size())
		return (true);
	return (false);
}

static void	doubleDistance(const std::vector<std::vector<char>>& input, const Point& a, const Point& b)
{
	Point	newA{a.x + (a.x - b.x), a.y + (a.y - b.y)};
	Point	newB{b.x - (a.x - b.x), b.y - (a.y - b.y)};

	if (isInBounds(input, newA) == true)
	{
		// std::cout << "Point: (" << newA.x << "," << newA.y << ")" << std::endl;
		freQ.insert(newA);
	}
	if (isInBounds(input, newB) == true)
	{
		// std::cout << "Point: (" << newB.x << "," << newB.y << ")" << std::endl;
		freQ.insert(newB);
	}
}

static size_t	countFrequencies(std::vector<std::vector<char>>& input, char c)
{
	std::vector<Point>	locations = getLocations(input, c);
	size_t	count = 0;

	if (locations.size() == 0)
		return (0);
	for (size_t x = 0; x < locations.size(); x++)
	{
		for (size_t y = x + 1; y < locations.size(); y++)
		{
			// std::cout << "Character: " << c << std::endl;
			doubleDistance(input, locations[x], locations[y]);
		}
		// exit(0);
	}
	return (count);
}

void	silver(std::vector<std::vector<char>>& input)
{
	for (size_t i = 0; i < 127; i++)
	{
		if (!(std::isalnum(static_cast<int> (i)) == false))
		{
			countFrequencies(input, static_cast<char> (i));
		}
	}
	std::cout << "Silver: " << freQ.size() << std::endl;
}