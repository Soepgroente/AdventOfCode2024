#include "day2.hpp"

void	print2dArray(std::array<std::vector<int>, INPUTSIZE>& levels)
{
	for (size_t i = 0; i < levels.size(); i++)
	{
		for (size_t j = 0; j < levels[i].size(); j++)
		{
			std::cout << levels[i][j] << " ";
		}
		std::cout << std::endl;
	}
}