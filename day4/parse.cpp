#include "day4.hpp"

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
	for (int j = 4; j < 144; j++)
	{
		std::getline(file, tmp, '\n');
		for (int i = 0; i < 148; i++)
		{
			if (i >= 144 || i < 4)
				g[j][i] = '.';
			else
				g[j][i] = tmp[i - 4];
		}
	}
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 148; i++)
			g[j][i] = '.';
	}
	for (int j = 144; j < 148; j++)
	{
		for (int i = 0; i < 148; i++)
			g[j][i] = '.';
	}
}