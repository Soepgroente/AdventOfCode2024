#include "day2.hpp"

static bool	singleLevel(const std::vector<int>& level)
{
	int	diff;

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

void	silver(std::array<std::vector<int>, INPUTSIZE>& levels)
{
	uint64_t	result = 0;

	for (size_t i = 0; i < levels.size(); i++)
	{
		result += singleLevel(levels[i]);
	}
	std::cout << "Silver: " << result << std::endl;
}