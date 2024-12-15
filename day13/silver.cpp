#include "day13.hpp"

int	smallestCommonNumber(std::map<int, int>& listA, std::map<int, int>& listB)
{
	size_t i = 0, j = 0, result = SIZE_MAX;

	while (i < listA.size() && j < listB.size())
	{
		if (listA[i] == listB[j])
		{
			size_t tmp = listA[i].first * 3 + listA[i].second;
			if (tmp < result)
			{
				result = tmp;
			}
		}
		if (listA[i] < listB[j])
			i++;
		else
			j++;
	}
	if (result == SIZE_MAX)
		return (0);
	std::cout << "Result: " << result << std::endl;
	return (result);
}

std::map<int, int>	multiples(int a, int b, int prize)
{
	std::map<int, int>	list;

	int		remainingPrize = 0;
	int		pressedB = 0;

	for (int pressedA = 0; a * pressedA <= prize && pressedA < 100; pressedA++)
	{
		remainingPrize = prize - a * pressedA;
		if (remainingPrize % b == 0)
		{
			pressedB = remainingPrize / b;
			if (pressedB < 100)
			{
				std::cout << "Prize: " << prize << " remaining: " << remainingPrize << " a: " << i << " b: " << pressedB << std::endl;
				list.insert(pressedA, pressedB);
			}
		}
	}
	return (list);
}

size_t	calculateMachine(const SlotMachine& slot)
{
	std::map<int, int>	listX;
	std::map<int, int>	listY;
	
	puts("A");
	listX = multiples(slot.buttonA.x, slot.buttonB.x, slot.Prize.x);
	puts("B");
	listY = multiples(slot.buttonA.y, slot.buttonB.y, slot.Prize.y);
	return (smallestCommonNumber(listX, listY));
}

void	silver(std::vector<SlotMachine> slots)
{
	size_t total = 0;

	for (SlotMachine& it : slots)
	{
		total += calculateMachine(it);
	}
	std::cout << "Silver: " << total << std::endl;
}