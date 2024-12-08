#pragma once

#include <algorithm>
#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

extern std::vector<std::vector<size_t>>	equations;

std::vector<std::string>	parseInput(std::string location);
void	silver();
void	gold();

template <typename T>
void	printArray(T& array)
{
	for (size_t i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}