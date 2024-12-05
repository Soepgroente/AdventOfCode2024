#include "day4.hpp"

char	g[148][148];

int main()
{
	parseInput("input.txt");
	for (int i = 0; i < 148; i++)
	{
		for (int j = 0; j < 148; j++)
		{
			std::cout << g[i][j];
		}
		std::cout << std::endl;
	}
	silver();
	gold();
}