#pragma once

#include <algorithm>
#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

extern std::vector<std::vector<int>>	pages;
extern std::vector<std::vector<int>>	manual;

void	parseInput();
void	silver();
void	gold();

template <typename T>
void	print2dArray(T& array)
{
	for (size_t i = 0; i < array.size(); i++)
	{
		for (size_t j = 0; j < array[i].size(); j++)
		{
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}