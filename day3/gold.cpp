#include "day3.hpp"

static int	checkValidity(std::string in)
{
	int a = 0, b = 0;

	std::string	subby;

	if (in.find_first_of(')') == std::string::npos)
		return (0);

	subby = in.substr(4, in.find_first_of(',') - 4);

	try {a = std::stoi(subby);}
	catch (std::exception& e){return (0);}

	subby = in.substr(in.find_first_of(',') + 1, in.find_first_of(')') - 1);

	try {b = std::stoi(subby);}
	catch (std::exception& e){return (0);}

	if (!(a > 0 && a < 1000) || !(b > 0 && b < 1000))
		return (0);
	return (a * b);
}

static std::vector<int>	messToInts(std::vector<std::string> input) 
{
	std::vector<int>	multis;
	const std::string	search = "mul(";
	size_t				position = 0;

	for (std::string& str : input)
	{
		position = str.find(search);
		while (position != std::string::npos)
		{
			str = str.substr(position);
			multis.emplace_back(checkValidity(str.substr(0, (sizeof("mul(999,999)")) - 1)));
			position = str.find(search, 1);
		}
	}
	return (multis);
}

void	gold(std::vector<std::string>& input)
{
	uint64_t	result = 0;
	std::vector<int>	multis = messToInts(input);

	for (size_t i = 0; i < multis.size(); i++)
	{
		result += multis[i];
	}
	std::cout << "Gold: " << result << std::endl;
}