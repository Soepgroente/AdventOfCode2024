#include "day6.hpp"

char	g[XSIZE][YSIZE];

int main()
{
	parseInput("input.txt");
	for (int i = 0; i < XSIZE; i++)
	{
		for (int j = 0; j < YSIZE; j++)
		{
			if (g[i][j] == '^')
			{
				silver(i, j);
				gold(i, j);
			}
		}
	}
}