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

static bool	isInvalidPage(std::vector<int>& man)
{
	for (size_t i = 0; i < man.size() - 1; i++)
	{
		for (size_t j = i + 1; j < man.size(); j++)
		{
			if (singleEntry(man[i], man[j]) == false)
				return (true);
		}
	}
	return (false);
}

static size_t	fixAndCountPage(std::vector<int>& man)
{
	while (isInvalidPage(man) == true)
	{
		for (size_t i = 0; i < man.size() - 1; i++)
		{
			for (size_t j = i + 1; j < man.size(); j++)
			{
				if (singleEntry(man[i], man[j]) == false)
				{
					man[i] = man[i] ^ man[j];
					man[j] = man[i] ^ man[j];
					man[i] = man[i] ^ man[j];
				}
			}
		}
	}
	return (man[man.size() / 2]);
}

void	gold()
{
	size_t	count = 0;

	for (size_t i = 0; i < manual.size(); i++)
	{
		if (isInvalidPage(manual[i]) == false)
		{
			manual.erase(manual.begin() + i);
			i--;
		}
	}
	for (size_t i = 0; i < manual.size(); i++)
	{
		count += fixAndCountPage(manual[i]);	
	}
	std::cout << "Gold: " << count << std::endl;
}