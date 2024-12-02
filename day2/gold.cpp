#include "day2.hpp"

static void	handleRemoval(std::vector<int>& level)
{

}

static bool	singleLevel(std::vector<int>& level)
{
	int	diff;

	handleRemoval(level);
	if (level[0] - level[1] < 0)
	{
		for (size_t i = 0; i < level.size() - 1; i++)
		{
			diff = level[i] - level[i + 1];
			if (!(diff <= -1 && diff >= -3))
				return (false);
		}
	}
	else
	{
		for (size_t i = 0; i < level.size() - 1; i++)
		{
			diff = level[i] - level[i + 1];
			if (!(diff >= 1 && diff <= 3))
				return (false);
		}
	}
	return (true);
}

void	gold(std::array<std::vector<int>, 1000>& levels)
{
	uint64_t	result = 0;

	for (size_t i = 0; i < levels.size(); i++)
	{
		result += singleLevel(levels[i]);
	}
	std::cout << "Gold: " << result << std::endl;
}