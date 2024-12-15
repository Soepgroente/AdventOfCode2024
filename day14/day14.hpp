#pragma once

#include <algorithm>
#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <cmath>
#include <set>
#include <span>
#include <sstream>
#include <string>
#include <unistd.h>
#include <vector>

#include "Point.hpp"

#define WIDTH 103
#define HEIGHT 101

/*	Parse	*/

std::vector<std::pair<Point, Point>>	parseInput(std::string location);

/*	Main	*/

void	silver(std::vector<std::pair<Point, Point>> input);
void	gold(std::vector<std::pair<Point, Point>>& input);

/*	Utils	*/

void	printRobots(std::vector<std::vector<int>>& tree);

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