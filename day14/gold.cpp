#include "day14.hpp"

static int	symmetryScore(std::vector<std::vector<int>>& tree)
{
	int score;

	for (int x = 0; x < HEIGHT; x++)
	{
		for (int y = 0; y < WIDTH; y++)
		{
			score = 0;
			while (y < WIDTH && tree[x][y] != 0)
			{
				y++;
				score++;
			}
			if (score > 10)
				return (true);
		}

	}
	return (false);
}

static void	setNextLocation(Point& location, Point& velocity)
{
	location = location + velocity;
	if (location.x < 0)
		location.x = HEIGHT + location.x;
	if (location.y < 0)
		location.y = WIDTH + location.y;
	location.x = location.x % HEIGHT;
	location.y = location.y % WIDTH;
}

static std::vector<std::vector<int>>	init(std::vector<std::pair<Point, Point>>& robots)
{
	std::vector<std::vector<int>>	tree;

	tree.resize(HEIGHT);
	for (size_t x = 0; x < HEIGHT; x++)
	{
		for (size_t y = 0; y < WIDTH; y++)
		{
			tree[x].push_back(0);
		}
	}
	for (std::pair<Point, Point> it : robots)
	{
		tree[it.first.x][it.first.y]++;
	}
	return (tree);
}

void	gold(std::vector<std::pair<Point, Point>>& robots)
{
	std::string tmp;
	std::vector<std::vector<int>>	tree = init(robots);

	for (size_t iter = 1; iter < 100000; iter++)
	{
		for (size_t i = 0; i < robots.size(); i++)
		{
			tree[robots[i].first.x][robots[i].first.y]--;
			setNextLocation(robots[i].first, robots[i].second);
			tree[robots[i].first.x][robots[i].first.y]++;
		}
		if (symmetryScore(tree) == true)
		{
			std::cout << "iteration: " << iter << std::endl;
			printRobots(tree);
		}
		// std::getline(std::cin, tmp, '\n');
	}
}