#include "Point.hpp"

Fixed crossProduct(Point const a, Point const b){
	return a.getX() * b.getY() - a.getY() * b.getX(); 
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
	Fixed cross1 = crossProduct( b - a, point - a);
	Fixed cross2 = crossProduct( c - b, point - b);
	Fixed cross3 = crossProduct( a - c, point - c);
	Fixed zero = Fixed(0);
	if ((cross1 < zero && cross2 < zero && cross3 < zero) || (cross1 > zero && cross2 > zero && cross3 > zero)) {
		return true;
	}
	return false;	
}
