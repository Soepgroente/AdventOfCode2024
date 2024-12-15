#pragma once

#include <iostream>

struct Point
{
    int x, y;

	Point(int a, int b) : x(a), y(b){};
	bool operator==(const Point& other)	const
	{
		return (x == other.x && y == other.y);
	}
	bool operator<(const Point& other)	const
	{
		if (x < other.x)
			return (true);
		if (x == other.x && y < other.y)
			return (true);
		return (false);
	}
	Point operator+(const Point& other)	const
	{
		return (Point{this->x + other.x, this->y + other.y});
	}
	Point operator-(const Point& other)	const
	{
		return (Point{this->x - other.x, this->y - other.y});
	}
};

inline std::ostream&	operator<<(std::ostream& out, const Point& toPrint)
{
	out << "x: " << toPrint.x << " y: " << toPrint.y << std::endl;
	return (out);
}