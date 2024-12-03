#pragma once

#include <algorithm>
#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string>	parseInput(std::string location);
void	silver(std::vector<std::string>& input);
void	gold(std::vector<std::string>& input);
// void	print2dArray(std::array<std::vector<int>, INPUTSIZE>& levels);