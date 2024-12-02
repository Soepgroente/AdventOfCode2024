#pragma once

#include <algorithm>
#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string>	parseInput();
void	silver(std::array<std::vector<int>, 1000>& levels);
void	gold(std::array<std::vector<int>, 1000>& levels);
void	print2dArray(std::array<std::vector<int>, 1000>& levels);