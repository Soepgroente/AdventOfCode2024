#pragma once

#include <algorithm>
#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define XSIZE 130
#define YSIZE 130

extern char	g[XSIZE][YSIZE];

void	parseInput(std::string location);
void	silver(int xStart, int yStart);
void	gold(int xPos, int yPos);
// void	print2dArray(std::array<std::vector<int>, INPUTSIZE>& levels);