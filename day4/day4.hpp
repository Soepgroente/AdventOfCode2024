#pragma once

#include <algorithm>
#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

extern char	g[148][148];

void	parseInput(std::string location);
void	silver();
void	gold();
// void	print2dArray(std::array<std::vector<int>, INPUTSIZE>& levels);