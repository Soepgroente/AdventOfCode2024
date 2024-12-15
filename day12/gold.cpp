#include "day12.hpp"

size_t	areaSize2;

static bool	isValidCell(std::vector<std::vector<bool>>& area, int x, int y)
{
	if (x < 0 || y < 0 || (size_t)x >= area.size() || (size_t)y >= area[x].size() || area[x][y] == false)
		return (false);
	return (true);
}

static bool	changingDirection(std::vector<std::vector<bool>>& area, int x, int y, int& incoming)
{
	const int dx[] = {0, 1, 0, -1};
    const int dy[] = {1, 0, -1, 0};
	int leftx, lefty;
	int straightx, straighty;

	incoming += 4;
	leftx = x + dx[(incoming - 1) % 4];
	lefty = y + dy[(incoming - 1) % 4];
	straightx = x + dx[incoming % 4];
	straighty = y + dy[incoming % 4];
	if (isValidCell(area, leftx, lefty) == true && area[leftx][lefty] == true)
	{
		incoming = (incoming - 1) % 4;
		return (true);
	}
	if (isValidCell(area, straightx, straighty) == true && area[straightx][straighty] == true)
	{
		incoming = incoming % 4;
		return (false);
	}
	incoming = (incoming + 1) % 4;
	return (true);
}

static size_t	getDirections(std::vector<std::vector<bool>>& area, int startX, int startY)
{
	const int dx[] = {0, 1, 0, -1};
    const int dy[] = {1, 0, -1, 0};
	size_t	sides = 1;
	int x = startX;
	int y = startY;
	int direction = 0;

	for (std::vector<bool>& it : area)
	{
		printArray(it, 0);
	}
	while (!(sides > 0 && x == startX && y == startY && direction == 3))
	{
		// std::cout << "x: " << x << " y: " << y << " direction: " << direction << " (sides): " << sides << std::endl;
		if (changingDirection(area, x, y, direction) == true)
			sides++;
		x += dx[direction];
		y += dy[direction];
		if (isValidCell(area, x, y) == false)
		{
			x -= dx[direction];
			y -= dy[direction];
		}
	}
	std::cout << sides << std::endl;
	return (sides);
}

static size_t	getSides(std::vector<std::vector<char>>& grid, size_t startX, size_t startY, char flower)
{
    std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
	const int dx[] = {0, 1, 0, -1};
    const int dy[] = {1, 0, -1, 0};

    auto searchPerimeter = [&](auto&& self, int x, int y) -> void
	{
		if (x < 0 || (size_t)x >= grid.size() || y < 0 || (size_t)y >= grid[x].size() || grid[x][y] != flower || visited[x][y] == true)
		{
            return ;
        }
        visited[x][y] = true;
        for (size_t i = 0; i < 4; i++)
		{
			int newX = x + dx[i];
            int newY = y + dy[i];
			if (newX < 0 || (size_t)newX >= grid.size() || newY < 0 || (size_t)newY >= grid[newX].size() || grid[newX][newY] != flower)
			{
				continue ;
			}
            if (visited[newX][newY] == false)
			{
                self(self, newX, newY);
            }
		}
    };
    searchPerimeter(searchPerimeter, startX, startY);
    return (getDirections(visited, startX, startY));
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
		areaSize2++;
		getArea(g, x, y + 1, flower);
	}
	if ((size_t)x < g.size() - 1 && g[x + 1][y] == flower)
	{
		areaSize2++;
		getArea(g, x + 1, y, flower);
	}
	if (x > 0 && g[x - 1][y] == flower)
	{
		areaSize2++;
		getArea(g, x - 1, y, flower);
	}
	if (y > 0 && g[x][y - 1] == flower)
	{
		areaSize2++;
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

void	gold(std::vector<std::vector<char>>& input)
{
	size_t	perimeterSides, total = 0;
	int x = 0, y = 0;
	bool isInsideAnother = false;

	while (gridIsEmpty(input) == false)
	{
		areaSize2 = 1;
		findNextGarden(input, x, y);
		perimeterSides = getSides(input, x, y, input[x][y]);
		if (isInsideAnother == true)
			perimeterSides *= 2;
		// std::cout << "Flower: " << input[x][y] << ", sides: " << perimeterSides << std::endl;
		getArea(input, x, y, input[x][y]);
		total += perimeterSides * areaSize2;
	}
	std::cout << "Gold: " << total << std::endl;
}