#include "day11.hpp"

int main()
{
	std::vector<size_t>	input = parseInput("input.txt");
	clock_t start, end;

	start = clock();
	silver(input);
	end = clock();
	std::cout << "Silver took: " << (end - start) << "ms" << std::endl;
	start = clock();
	gold(input);
	end = clock();
	std::cout << "Gold took: " << (end - start) << "ms" << std::endl;
}