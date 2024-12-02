#include "day2.hpp"

std::array<std::vector<int>, INPUTSIZE>	createArrays(std::vector<std::string>& input) 
{
	std::array<std::vector<int>, INPUTSIZE>	levels;

	for (size_t i = 0; i < levels.size(); i++)
	{
		std::istringstream stream(input[i]);
		int value = -1;

		while (stream >> value)
		{
		    levels[i].emplace_back(value);
		}
	}
	return (levels);
}

int main()
{
	std::vector<std::string>	input = parseInput();
	std::array<std::vector<int>, INPUTSIZE> levels = createArrays(input);

	// print2dArray(levels);

	silver(levels);
	gold(levels);
}