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

#include "Point.hpp"

enum	dirs
{
	LEFT,
	UP,
	RIGHT,
	DOWN,
	WALL = '#',
	EMPTY = '.',
	ROBOT = '@',
	BOX = 'O',
	BOXL = '[',
	BOXR = ']'
};

/*	Parse	*/

std::vector<std::vector<char>>	parseInput(std::string location);
std::vector<int>				parseDirs(std::string location);

/*	Main	*/

void							silver(std::vector<std::vector<char>> input, std::vector<int>& directions, Point fish);
void							gold(std::vector<std::vector<char>> input, std::vector<int>& directions, Point fish);

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