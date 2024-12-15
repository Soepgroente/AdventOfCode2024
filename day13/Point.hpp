#pragma once

#include <iostream>

struct Point
{
    int x, y;

	Point(int a, int b) : x(a), y(b){};
	Point() {x = 0, y = 0;}
	~Point() = default;
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
		return (Point(this->x + other.x, this->y + other.y));
	}
	Point operator-(const Point& other)	const
	{
		return (Point{this->x - other.x, this->y - other.y});
	}
	Point operator*(int multiplier)
	{
		return (Point(this->x * multiplier, this->y * multiplier));
	}
};

inline std::ostream&	operator<<(std::ostream& out, const Point& toPrint)
{
	out << "x: " << toPrint.x << " y: " << toPrint.y;
	return (out);
}