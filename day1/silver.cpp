#include "day1.hpp"

void	silver(std::array<int, 1000>& left, std::array<int, 1000>& right)
{
	uint64_t	result = 0;

	for (int i = 0; i < 1000; i++)
	{
		result += abs(left[i] - right[i]);
	}
	std::cout << "Silver: " << result << std::endl;
}