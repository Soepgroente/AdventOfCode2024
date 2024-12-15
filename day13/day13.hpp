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

struct SlotMachine
{
	Point	buttonA;
	Point	buttonB;
	Point	Prize;
};

inline std::ostream&	operator<<(std::ostream& out, const SlotMachine& toPrint)
{
	out << "button A: " << toPrint.buttonA << " button B: " << toPrint.buttonB << " prize: " << toPrint.Prize;
	return (out);
}

/*	Parse	*/

std::vector<SlotMachine>	parseInput(std::string location);

/*	Main	*/

void	silver(std::vector<SlotMachine> input);
void	gold(std::vector<SlotMachine> input);

/*	Utils	*/

int	gcd(int a, int b);

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