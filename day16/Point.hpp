#pragma once

#include <iostream>

struct Point
{
    int x, y;

	Point() = default;
	~Point() = default;
	Point(int a, int b);

	bool	operator==(const Point& other)	const;
	bool	operator!=(const Point& other)	const;
	bool	operator<(const Point& other)	const;
	Point	operator+(const Point& other)	const;
	Point	operator-(const Point& other)	const;
	Point	operator*(int multiplier)		const;
};

std::ostream&	operator<<(std::ostream& out, const Point& toPrint);