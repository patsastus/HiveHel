#include "Point.hpp"

Point::Point() : x_(Fixed()), y_(Fixed()) {
}

Point::Point(const float x, const float y) : x_(Fixed(x)), y_(Fixed(y)){
}

Point::Point(const Fixed x, const Fixed y) : x_(Fixed(x)), y_(Fixed(y)){
}

Point::Point(const Point& other) : x_(Fixed(other.getX())), y_(Fixed(other.getY())) {
}

Point& Point::operator=(const Point& other){
	//because member attributes are const, assignment is actually impossible
	//just satisfy requirements of OCF
	(void)other;
	return *this;
}

Fixed Point::getX() const{
	return x_;
}

Fixed Point::getY() const{
	return y_;
}

Point Point::operator-(const Point& other) const {
	return Point(
		(this->getX() - other.getX()),
		(this->getY() - other.getY())
	);
}

Point::~Point() {
    
}
