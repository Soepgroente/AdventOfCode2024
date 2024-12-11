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

static void	blink(std::vector<size_t>& input)
{
	int digits;
	std::vector<size_t>	temp;

	for (size_t i = 0; i < input.size(); i++)
	{
		digits = 0;
		if (input[i] == 0)
			temp.push_back(1); 
		else if (amountOfDigits(input[i], digits) == true)
		{
			size_t	entries[2]{0, 0};
			splitNumber(digits / 2, input[i], entries);
			temp.push_back(entries[0]);
			temp.push_back(entries[1]);
		}
		else
		{
			temp.push_back(input[i] * 2024);
		}
	}
	input = temp;
}

void	silver(std::vector<size_t> input)
{
	for (int i = 0; i < 25; i++)
	{
		blink(input);
	}
	std::cout << "Silver: " << input.size() << std::endl;
}
