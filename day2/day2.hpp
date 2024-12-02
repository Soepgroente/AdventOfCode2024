#pragma once

#include <algorithm>
#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define INPUTSIZE 1000

std::vector<std::string>	parseInput();
void	silver(std::array<std::vector<int>, INPUTSIZE>& levels);
void	gold(std::array<std::vector<int>, INPUTSIZE>& levels);
void	print2dArray(std::array<std::vector<int>, INPUTSIZE>& levels);