#include "Fixed.hpp"

Fixed::Fixed() : value_(0){
	std::cout << "Default constructor called"<< std::endl;
}

Fixed::Fixed(const int in) {
	std::cout << "Int constructor called"<< std::endl;
	int temp;
	bool overflow = false;
	if (in > (std::numeric_limits<int>::max() >> fractionalBits_)){
		temp = std::numeric_limits<int>::max();
		overflow = true;
	}
	if (in < (std::numeric_limits<int>::min() >> fractionalBits_)){
		temp = std::numeric_limits<int>::min();
		overflow = true;
	}
	if (overflow)
		setRawBits(temp);
	else
		setRawBits(in << fractionalBits_);
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called"<< std::endl;
	int temp;
	bool overflow = false;
	if (f > ((float)std::numeric_limits<int>::max() / (float)(1 << fractionalBits_))){
		temp = std::numeric_limits<int>::max();
		overflow = true;
	}
	if (f < ((float)std::numeric_limits<int>::min() / (float)(1 << fractionalBits_))){
		temp = std::numeric_limits<int>::min();
		overflow = true;
	}
	if (overflow)
		setRawBits(temp);
	else 
		setRawBits((int)roundf(f * (float)(1 << fractionalBits_))); 
	//multiply float by (1<<fB) <-> multiply by 2^fB <-> shift int left by fB
}

Fixed::Fixed(const Fixed& other) : value_(other.value_){
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        value_ = other.value_;
    }
    return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	return value_;
}

void Fixed::setRawBits(int const raw) {
	value_ = raw;
}

float Fixed::toFloat() const{
	return (float)getRawBits() / (float)(1 << fractionalBits_); //divide by 256 = 2^8 <-> shift right by 8 bits
}

int Fixed::toInt() const{
	return getRawBits() >> fractionalBits_;
}

int Fixed::getFractionalBits() {
	return fractionalBits_;
}

//needs to call the class function getFB() because we're not allowed friends
std::ostream& operator<<(std::ostream& os, const Fixed& f) { 
	os << (double)f.getRawBits() / (double)(1 << Fixed::getFractionalBits());
    return os;
}
