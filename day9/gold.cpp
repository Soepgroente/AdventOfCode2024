#include "day9.hpp"

static int	getFreeSpaceIndex(std::vector<int>& newHardDisc, int size, size_t limit)
{
	int tmp;

	for (size_t i = 0; i < limit; i++)
	{
		tmp = 0;
		while (newHardDisc[i] == -1)
		{
			tmp++;
			i++;
			if (tmp == size)
				return (i - tmp);
		}
	}
	return (-1);
}

static int	getFileSize(std::vector<int>& hd)
{
	int size = 0;
	int index = std::distance(hd.begin(), hd.end() - 1);

	int num = hd[index];
	while (index >= 0 && hd[index] == num)
	{
		size++;
		index--;
	}
	return (size);
}

static void	deleteEmpty(std::vector<int>& hd, int& right)
{
	while (hd.size() > 0 && hd[right] == -1)
	{
		hd.pop_back();
		right--;
	}
}

static std::vector<int>	reorderHardDisc(std::vector<int>& hd)
{
	std::vector<int>	newHardDisc = hd;
	int fileSize, freeSpaceIndex;
	int right = std::distance(hd.begin(), hd.end() - 1);

	// printDrive(newHardDisc);
	while (hd.size() > 0 && right >= 6)
	{
		deleteEmpty(hd, right);
		if (hd.size() == 0)
			return (newHardDisc);

		fileSize = getFileSize(hd);
		freeSpaceIndex = getFreeSpaceIndex(newHardDisc, fileSize, right);
		if (freeSpaceIndex != -1)
		{
			for (int q = 0; q < fileSize; q++)
			{
				newHardDisc[freeSpaceIndex + q] = hd[right];
				newHardDisc[right] = -1;
				hd.pop_back();
				right--;
				if (hd.size() == 0)
					return (newHardDisc);
			}
		}
		else
		{
			while (hd[right] != -1)
			{
				hd.pop_back();
				right--;
				if (hd.size() == 0)
					return (newHardDisc);
			}
		}
	}
	return (newHardDisc);
}

void	gold(std::string& input)
{
	std::vector<int>	transformedInput, newHardDisc;
	size_t result = 0;

	transformedInput = transform(input.size(), input.c_str());
	newHardDisc = reorderHardDisc(transformedInput);
	// printDrive(newHardDisc);
	for (size_t i = 0; i < newHardDisc.size(); i++)
	{
		if (newHardDisc[i] != -1)
			result += i * newHardDisc[i];
	}
	std::cout << "Gold: " << result << std::endl;
}