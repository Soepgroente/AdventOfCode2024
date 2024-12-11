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

struct Point
{
    int x, y;

	bool operator==(const Point& other)	const
	{
		return (x == other.x && y == other.y);
	}
	bool operator<(const Point& other)	const
	{
		if (x < other.x)
			return (true);
		if (x == other.x && y < other.y)
			return (true);
		return (false);
	}
	Point operator+(const Point& other)	const
	{
		return (Point{this->x + other.x, this->y + other.y});
	}
	Point operator-(const Point& other)	const
	{
		return (Point{this->x - other.x, this->y - other.y});
	}
};

std::vector<std::vector<int>>	parseInput(std::string location);
void							silver(std::vector<std::vector<int>>& map);
void							gold(std::vector<std::vector<int>>& map);

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