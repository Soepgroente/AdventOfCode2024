#include "day7.hpp"

#define CONCATENATE 0
#define MULTI 1
#define ADD 2

static void	addNumbers(std::vector<size_t>& array, size_t a, size_t b)
{
	array[1] = a + b;
}

static void	multiplyNumbers(std::vector<size_t>& array, size_t a, size_t b)
{
	array[1] = a * b;
}

static void	concatenateNumbers(std::vector<size_t>& array, size_t a, size_t b)
{
	array[1] = std::stoul(std::to_string(a) + std::to_string(b));
}

static size_t	calculateResult(std::vector<size_t> array, std::vector<int8_t>& operations)
{
	void	(*f[3])(std::vector<size_t>&, size_t, size_t) = {&concatenateNumbers, &multiplyNumbers, &addNumbers};

	for (size_t i = 0; i < operations.size(); i++)
	{
		f[operations[i]](array, array[1], array[2]);
		array.erase(array.begin() + 2);
	}
	return (array[1]);
}

static bool	canSolve(std::vector<size_t>& array, std::vector<int8_t>& operations, size_t pos)
{
	pos++;
	while (pos < array.size())
	{
		operations.emplace_back(CONCATENATE);
		if (canSolve(array, operations, pos) == true)
			return (true);
		operations.back() = MULTI;
		if (canSolve(array, operations, pos) == true)
			return (true);
		operations.back() = ADD;
		if (canSolve(array, operations, pos) == true)
			return (true);
		operations.pop_back();
		return (false);
	}
	if (calculateResult(array, operations) == array[0])
		return (true);
	return (false);
}

void	gold()
{
	size_t	count = 0;
	std::vector<int8_t> operations;

	for (size_t i = 0; i < equations.size(); i++)
	{
		count += canSolve(equations[i], operations, 1) * equations[i][0];
		operations.clear();
	}
	std::cout << "Gold: " << count << std::endl;
}
