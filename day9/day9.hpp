#pragma once

#include <algorithm>
#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <span>
#include <sstream>
#include <string>
#include <vector>

std::string			parseInput(std::string location);
void				silver(std::string& input);
void				gold(std::string& input);
std::vector<int>	transform(size_t size, const char* str);
void				printDrive(std::vector<int>& hd);

template <typename T>
void	printArray(T& array, char space)
{
	for (size_t i = 0; i < array.size(); i++)
	{
		std::cout << array[i];
		if (space != '\0')
			std::cout << space;
	}
	std::cout << std::endl;
}