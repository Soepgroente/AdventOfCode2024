#include "day2.hpp"

static bool	singleLevel(const std::vector<int> level)
{
	int		diff;

	for (size_t x = 0; x < level.size(); x++)
	{
		std::vector<int> tmp = level;

		tmp.erase(tmp.begin() + x);
		if (tmp[0] - tmp[1] < 0)
		{
			for (size_t i = 0; i < tmp.size() - 1; i++)
			{
				diff = tmp[i] - tmp[i + 1];
				if (!(diff <= -1 && diff >= -3))
				{
					break ;
				}
				if (i == tmp.size() - 2)
					return (true);
			}
		}
		else
		{
			for (size_t i = 0; i < tmp.size() - 1; i++)
			{
				diff = tmp[i] - tmp[i + 1];
				if (!(diff >= 1 && diff <= 3))
				{
					break ;
				}
				if (i == tmp.size() - 2)
					return (true);
			}
		}
	}
	return (false);
}

void	gold(std::array<std::vector<int>, INPUTSIZE>& levels)
{
	uint64_t	result = 0;

	for (size_t i = 0; i < levels.size(); i++)
	{
		result += singleLevel(levels[i]);
	}
	std::cout << "Gold: " << result << std::endl;
}