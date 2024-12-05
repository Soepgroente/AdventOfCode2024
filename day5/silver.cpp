#include "day5.hpp"

static bool	singleEntry(int x, int y)
{
	for (size_t i = 0; i < pages.size(); i++)
	{
		if (x == pages[i][0] && y == pages[i][1])
			return (true);
	}
	return (false);
}

static size_t	singlePage(std::vector<int>& man)
{
	for (size_t i = 0; i < man.size() - 1; i++)
	{
		for (size_t j = i + 1; j < man.size(); j++)
		{
			if (singleEntry(man[i], man[j]) == false)
				return (0);
		}
	}
	return (man[man.size() / 2]);
}

void	silver()
{
	size_t	count = 0;

	for (size_t i = 0; i < manual.size(); i++)
		count += singlePage(manual[i]);

	std::cout << "Silver: " << count << std::endl;
}