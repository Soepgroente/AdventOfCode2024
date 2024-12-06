#include "day6.hpp"

void	parseInput(std::string location)
{
	std::ifstream	file;
	std::string		tmp;

	file.open(location);
	if (file.is_open() == false)
	{
		std::cerr << "Couldn't open input file" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	for (int x = 0; x < XSIZE; x++)
	{
		std::getline(file, tmp, '\n');
		for (int y = 0; y < YSIZE; y++)
		{
			g[x][y] = tmp[y];
		}
	}
}