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
void	silver(std::array<int, 1000>& left, std::array<int, 1000>& right);
void	gold(std::array<int, 1000>& left, std::array<int, 1000>& right);
