#include "day9.hpp"

std::vector<int>	transform(size_t size, const char* str)
{
	std::vector<int>	transformedInput;
	size_t i = 0;
	int	fileLength, freeSpaceLength, count = 0;

	while (i < size)
	{
		fileLength = str[i] - '0';
		freeSpaceLength = str[i + 1] - '0';
		for (int x = 0; x < fileLength; x++)
			transformedInput.push_back(count);
		for (int x = 0; x < freeSpaceLength; x++)
			transformedInput.push_back(-1);
		i += 2;
		count++;
	}
	return (transformedInput);
}

void	printDrive(std::vector<int>& hd)
{
	for (size_t i = 0; i < hd.size(); i++)
	{
		if (hd[i] == -1)
			std::cout << ".|";
		else
			std::cout << hd[i] << "|";
	}
}