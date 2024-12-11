#include "day11.hpp"

size_t count;

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

static void	blink(std::vector<size_t>& input, int iter)
{
	int		digits;
	size_t	entries[2]{0, 0};

	while (iter < 5)
	{
		iter++;
		digits = 0;
		if (input[0] == 0)
		{
			input[0] = 1;
		}
		else if (amountOfDigits(input[0], digits) == true)
		{
			splitNumber(digits / 2, input[0], entries);
			input[0] = entries[0];
			input.push_back(entries[1]);
			// blink(input, iter);
		}
		else
		{
			input[0] *= 2024;
		}
	}
	input.erase(input.begin());
	count++;
}

void	gold(std::vector<size_t> input)
{
	size_t	amount;

	count = 0;
	amount = input.size();
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Iteration: " << i + 1 << std::endl;
		for (size_t x = 0; x < amount; x++)
		{
			blink(input, i);
			printArray(input, ' ');
			// printArray(input, ' ');
		}
	}
	std::cout << "Gold: " << count + input.size() << std::endl;
}
