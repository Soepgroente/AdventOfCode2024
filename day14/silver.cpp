#include "day14.hpp"

static void	setFutureLocation(Point& start, Point& velocity, int (&quadrant)[4])
{
	Point location;

	location = velocity * 100;
	location = location + start;
	if (location.x < 0)
		location.x = HEIGHT * 100 + location.x;
	if (location.y < 0)
		location.y = WIDTH * 100 + location.y;
	location.x = location.x % HEIGHT;
	location.y = location.y % WIDTH;
	start = location;

	if (start.x == HEIGHT / 2 || start.y == WIDTH / 2)
	{
		return ;
	}
	if (start.x < HEIGHT / 2 && start.y < WIDTH / 2)
		quadrant[0]++;
	if (start.x < HEIGHT / 2 && start.y > WIDTH / 2)
		quadrant[1]++;
	if (start.x > HEIGHT / 2 && start.y < WIDTH / 2)
		quadrant[2]++;
	if (start.x > HEIGHT / 2 && start.y > WIDTH / 2)
		quadrant[3]++;
}

void	silver(std::vector<std::pair<Point, Point>> robots)
{
	int quadrant[4] = {0, 0, 0, 0};

	for (std::pair<Point, Point>& it : robots)
	{
		setFutureLocation(it.first, it.second, quadrant);
	}
	std::cout << "Quadrants: " << quadrant[0] << " " << quadrant[1] << " " << quadrant[2] << " " << quadrant[3] << std::endl;
	std::cout << "Silver: " << quadrant[0] * quadrant[1] * quadrant[2] * quadrant[3] << std::endl;
}