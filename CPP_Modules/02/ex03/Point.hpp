#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point {
public:
    Point();
	Point(const float x, const float y);
	Point(const Fixed x, const Fixed y);
    Point(const Point& other);
   	Point& operator=(const Point& other);
	~Point();

	Point operator-(const Point& other) const;
	Fixed getX() const;
	Fixed getY() const;

private:
	const Fixed x_;
	const Fixed y_;
};

#endif // POINT_HPP
