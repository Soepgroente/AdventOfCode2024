#pragma once

#include <algorithm>
#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <span>
#include <sstream>
#include <string>
#include <unistd.h>
#include <vector>
#include <queue>
#include <unordered_map>
#include <functional>
#include <cmath>
#include <limits>

#include "Point.hpp"

enum	dirs
{
	WALL = -1,
	LEFT,
	UP,
	RIGHT,
	DOWN,
	EMPTY = '.',
	EXIT = 'E'
};

/*	Parse	*/

std::vector<std::vector<char>>	parseInput(std::string location);

/*	Main	*/

void	silver(std::vector<std::vector<char>> in, Point start, Point end);
void	gold(std::vector<std::vector<char>> in, Point start, Point end);

/*	Utils	*/

void							printGrid(std::vector<std::vector<char>>& grid);
size_t							getTotal(std::vector<std::vector<char>>& grid, char box);

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

template <typename T>
void	printGrid(std::vector<std::vector<T>>& grid)
{
	for (std::vector<T>& it : grid)
	{
		printArray(it, ' ');
	}
}
