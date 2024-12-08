#include "day7.hpp"

std::vector<std::vector<size_t>>	equations;

static size_t	nextNumber(std::string& input)
{
	size_t	nxt = std::stoul(input);
	return (nxt);
}

static void	strToNumbers(std::vector<std::string>& input)
{
	std::string			tmp;

	for (size_t x = 0; x < input.size(); x++)
	{
		std::istringstream	stream(input[x]);
		equations.emplace_back();
		while (stream >> tmp)
		{
			equations[x].emplace_back(nextNumber(tmp));
		}
	}
}

int main()
{
	std::vector<std::string>	input = parseInput("input.txt");

	strToNumbers(input);
	// silver();
	gold();
}
