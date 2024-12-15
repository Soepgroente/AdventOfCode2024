#include "day12.hpp"

size_t	areaSize;

/*	[&] gets references from all variables within scope, 
	-> void is the return type of the recursive function, 
	double&& refers to itself (as a function) to get recursive	*/

static size_t getPerimeter(std::vector<std::vector<char>>& grid, size_t startX, size_t startY, char flower)
{
    std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
    size_t perimeter = 0;
	const int dx[] = {0, 1, 0, -1};
    const int dy[] = {1, 0, -1, 0};

    auto searchPerimeter = [&](auto&& self, size_t x, size_t y) -> void
	{
		if (x < 0 || x >= grid.size() || y < 0 || y >= grid[x].size() || grid[x][y] != flower || visited[x][y] == true)
		{
            return;
        }
        visited[x][y] = true;
        for (size_t i = 0; i < 4; i++)
		{
			size_t newX = x + dx[i];
            size_t newY = y + dy[i];
			if (newX < 0 || newX >= grid.size() || newY < 0 || newY >= grid[newX].size() || grid[newX][newY] != flower)
			{
				perimeter++;
				continue;
			}
            if (visited[newX][newY] == false)
			{
                self(self, newX, newY);
            }
		}
    };
    searchPerimeter(searchPerimeter, startX, startY);
    return (perimeter);
}

static bool	gridIsEmpty(std::vector<std::vector<char>>& input)
{
	for (size_t x = 0; x < input.size(); x++)
	{
		for (size_t y = 0; y < input[x].size(); y++)
		{
			if (input[x][y] != '.')
				return (false);
		}
	}
	return (true);
}

static void	getArea(std::vector<std::vector<char>>& g, int x, int y, char flower)
{
	g[x][y] = '.';
	if ((size_t)y < g[x].size() - 1 && g[x][y + 1] == flower)
	{
		areaSize++;
		getArea(g, x, y + 1, flower);
	}
	if ((size_t)x < g.size() - 1 && g[x + 1][y] == flower)
	{
		areaSize++;
		getArea(g, x + 1, y, flower);
	}
	if (x > 0 && g[x - 1][y] == flower)
	{
		areaSize++;
		getArea(g, x - 1, y, flower);
	}
	if (y > 0 && g[x][y - 1] == flower)
	{
		areaSize++;
		getArea(g, x, y - 1, flower);
	}
	return ;
}



static void	findNextGarden(std::vector<std::vector<char>>& input, int& x, int& y)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		for (size_t j = 0; j < input[i].size(); j++)
		{
			if (input[i][j] != '.')
			{
				x = i;
				y = j;
				return ;
			}
		}
	}
}

void	silver(std::vector<std::vector<char>> input)
{
	size_t	perimeter, total = 0;
	int x = 0, y = 0;

	while (gridIsEmpty(input) == false)
	{
		areaSize = 1;
		findNextGarden(input, x, y);
		perimeter =	getPerimeter(input, x, y, input[x][y]);
		getArea(input, x, y, input[x][y]);
		total += perimeter * areaSize;
	}
	std::cout << "Silver: " << total << std::endl;
}