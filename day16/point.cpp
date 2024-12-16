#include "Point.hpp"

std::ostream&	operator<<(std::ostream& out, const Point& toPrint)
{
	out << "x: " << toPrint.x << " y: " << toPrint.y;
	return (out);
}

Point::Point(int a, int b) : x(a), y(b)
{
}

bool	Point::operator==(const Point& other)	const
{
	return (x == other.x && y == other.y);
}

bool	Point::operator!=(const Point& other)	const
{
	return (x != other.x || y != other.y);
}

bool	Point::operator<(const Point& other)	const
{
	if (x < other.x)
		return (true);
	if (x == other.x && y < other.y)
		return (true);
	return (false);
}

Point	Point::operator+(const Point& other)	const
{
	return (Point{this->x + other.x, this->y + other.y});
}

Point	Point::operator-(const Point& other)	const
{
	return (Point{this->x - other.x, this->y - other.y});
}

Point	Point::operator*(int multiplier)		const
{
	return (Point(this->x * multiplier, this->y * multiplier));
}