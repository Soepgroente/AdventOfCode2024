#include "day7.hpp"

static bool	canSolve(std::vector<size_t>& array, size_t result, size_t pos)
{
	while (pos < array.size())
	{
		result += array[pos];
		pos++;
		if (canSolve(array, result, pos) == true)
			return (true);
		result -= array[pos - 1];
		result *= array[pos - 1];
		if (canSolve(array, result, pos) == true)
			return (true);
		return (false);
	}
	if (result != array[0])
		return (false);
	return (true);
}

void	silver()
{
	size_t	count = 0;

	for (size_t i = 0; i < equations.size(); i++)
	{
		count += canSolve(equations[i], equations[i][1], 2) * equations[i][0];
	}
	std::cout << "Silver: " << count << std::endl;
}