#include "day3.hpp"
// #define FOREVER 1

// int	checkValidity(std::string in)
// {
// 	int a = 0, b = 0;

// 	std::string	subby;

// 	if (in.find_first_of(')') == std::string::npos)
// 	{
// 		std::cout << "this is a thing" << std::endl;
// 		return (0);
// 	}
// 	std::cout << in << std::endl;
// 	subby = in.substr(4, in.find_first_of(',') - 4);
// 	std::cout << subby << std::endl;

// 	try {a = std::stoi(subby);}
// 	catch (std::exception& e){return (0);}

// 	subby = in.substr(in.find_first_of(',') + 1, in.find_first_of(')') - 1);
// 	std::cout << subby << std::endl;

// 	try {b = std::stoi(subby);}
// 	catch (std::exception& e){return (0);}
// 	if (!(a > 0 && a < 1000) || !(b > 0 && b < 1000))
// 		return (0);
// 	std::cout << "a: " << a <<  " b: " << b << " a * b: " <<  a * b << std::endl << std::endl;
// 	return (a * b);
// }

// std::vector<int>	messToInts(std::vector<std::string> input) 
// {
// 	std::vector<int>	multis;
// 	const std::string	search = "mul(";
// 	size_t				position = 0;

// 	for (std::string& str : input)
// 	{
// 		position = str.find(search);
// 		while (position != std::string::npos)
// 		{
// 			str = str.substr(position);
// 			multis.emplace_back(checkValidity(str.substr(0, (sizeof("mul(999,999)")) - 1)));
// 			position = str.find(search, 1);
// 		}
// 	}
// 	return (multis);
// }

int main()
{
	std::vector<std::string>	input = parseInput("input.txt");
	std::vector<std::string>	goldInput = parseInput("goldinput.txt");

	silver(input);
	gold(goldInput);
}