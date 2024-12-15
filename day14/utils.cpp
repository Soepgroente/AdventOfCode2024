#include "day14.hpp"

void	printRobots(std::vector<std::vector<int>>& tree)
{
	for (size_t x = 0; x < HEIGHT; x++)
	{
		for (size_t y = 0; y < WIDTH; y++)
		{
			if (tree[x][y] == 0)
				std::cout << '.';
			else
				std::cout << tree[x][y];
		}
		std::cout << "\n";
	}
}
