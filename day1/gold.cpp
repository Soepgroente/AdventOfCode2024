#include "day1.hpp"

uint64_t	findRepeats(int left, std::array<int, 1000>& right)
{
	uint64_t	count = 0;

	for (int i = 0; i < 1000; i++)
	{
		if (right[i] == left)
			count++;
	}
	return (count);
}

void	gold(std::array<int, 1000>& left, std::array<int, 1000>& right)
{
	uint64_t	result = 0;

	for (int i = 0; i < 1000; i++)
	{
		result += (findRepeats(left[i], right) * left[i]);
	}
	std::cout << "Gold: " << result << std::endl;
}