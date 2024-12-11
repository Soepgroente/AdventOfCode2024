#include "day11.hpp"

static void	splitNumber(int digits, size_t in, size_t (&entries)[2])
{
	entries[0] = in / static_cast<size_t>(pow(10, digits));
	entries[1] = in % static_cast<size_t>(pow(10, digits));
}

static bool	amountOfDigits(size_t num, int& digits)
{
	while (num > 0)
	{
		num /= 10;
		digits++;
	}
	if (digits % 2 == 0)
		return (true);
	return (false);
}

/* static void	printMap(std::map<size_t, size_t>& toPrint)
{
	for (auto& it : toPrint)
	{
		std::cout << "(" << it.first << "," << it.second << ")" << std::endl;
	}
} */

static void	tryToShoveIntoMap(std::map<size_t, size_t>& map, size_t a, size_t b)
{
	auto [iter, check] = map.try_emplace(a, b);
	if (!check)
	{
		map[a] += b;
	}
}

static 	std::map<size_t, size_t>	blink(std::map<size_t, size_t>& data)
{
	int		digits;
	std::map<size_t, size_t>	newData;
	size_t	entries[2]{0, 0};

	for (auto& it : data)
	{
		digits = 0;
		if (it.first == 0)
		{
			tryToShoveIntoMap(newData, 1, it.second);
		}
		else if (amountOfDigits(it.first, digits) == true)
		{
			splitNumber(digits / 2, it.first, entries);
			tryToShoveIntoMap(newData, entries[0], it.second);
			tryToShoveIntoMap(newData, entries[1], it.second);
		}
		else
		{
			tryToShoveIntoMap(newData, it.first * 2024, it.second);
		}
	}
	return (newData);
}

void	gold(std::vector<size_t> input)
{
	size_t	count = 0;
	std::map<size_t, size_t>	data;

	for (size_t i = 0; i < input.size(); i++)
		data.insert({input[i], 1});
	// printMap(data);
	for (int i = 0; i < 25; i++)
	{
		data = blink(data);
		// std::cout << "Iteration: " << i + 1 << std::endl;
	}
	for (auto& it : data)
	{
		count += it.second;
	}
	// printMap(data);
	std::cout << "Gold: " << count << std::endl;
}
