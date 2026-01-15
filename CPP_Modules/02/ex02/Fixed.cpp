#include "Fixed.hpp"

Fixed::Fixed() : value_(0){
//	std::cout << "Default constructor called"<< std::endl;
}

Fixed::Fixed(const int in) {
//	std::cout << "Int constructor called"<< std::endl;
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
//	std::cout << "Float constructor called"<< std::endl;
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
		setRawBits((int)roundf(f * (float)(1 << fractionalBits_))); //multiply/divide by 256 = 2^8 <-> shift left/right by 8 bits
}

Fixed::Fixed(const Fixed& other) : value_(other.value_){
//	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
//	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        value_ = other.value_;
    }
    return *this;
}

Fixed::~Fixed() {
//	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	return value_;
}

void Fixed::setRawBits(int const raw) {
	value_ = raw;
}

float Fixed::toFloat() const{
	return (float)value_ / (float)(1 << fractionalBits_); //divide by 256 = 2^8 <-> shift right by 8 bits
}

int Fixed::toInt() const{
	return value_ >> fractionalBits_;
}

Fixed& Fixed::min(Fixed& a, Fixed& b){
	if (a.value_ <= b.value_)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
	if (a.value_ >= b.value_)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
	if (a.value_ <= b.value_)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
	if (a.value_ >= b.value_)
		return a;
	return b;
}

int Fixed::getFractionalBits() {
    return fractionalBits_;
}

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
    os << (double)f.getRawBits() / (double)(1 << Fixed::getFractionalBits());
    return os;
}

//minimize actual comparisons: all others reference this one or equality
//doesn't matter for this simple case, but good practice
bool Fixed::operator<(const Fixed& other) const {
    return this->value_ < other.value_;
}

bool Fixed::operator>(const Fixed& other) const {
    return (other < *this);
}

bool Fixed::operator>=(const Fixed& other) const {
    return !(*this < other);
}

bool Fixed::operator<=(const Fixed& other) const {
    return !(other < *this);
}

bool Fixed::operator==(const Fixed& other) const {
    return this->value_ == other.value_;
}

bool Fixed::operator!=(const Fixed& other) const {
    return !(*this == other);
}

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed result;
	int64_t tempRawBits = (int64_t)this->value_ + (int64_t)other.value_;
	if (tempRawBits > (std::numeric_limits<int>::max())) {
		result.setRawBits(std::numeric_limits<int>::max());
	} else if (tempRawBits < (std::numeric_limits<int>::min())) {
		result.setRawBits(std::numeric_limits<int>::min());
	}else {
	    result.setRawBits((int)tempRawBits);
	}
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;
	int64_t tempRawBits = (int64_t)this->value_ - (int64_t)other.value_;
	if (tempRawBits > (std::numeric_limits<int>::max())) {
		result.setRawBits(std::numeric_limits<int>::max());
	} else if (tempRawBits < (std::numeric_limits<int>::min())) {
		result.setRawBits(std::numeric_limits<int>::min());
	}else {
	    result.setRawBits((int)tempRawBits);
	}
	return result;
}

//Mutiplying two fixed point numbers means the result has 16 fractional bits, needs rightshift by 8 to correct back to Fixed
Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;
	int64_t tempRawBits = ((int64_t)this->value_ * (int64_t)other.value_) >> fractionalBits_;
	if (tempRawBits > (std::numeric_limits<int>::max())) {
		result.setRawBits(std::numeric_limits<int>::max());
	} else if (tempRawBits < (std::numeric_limits<int>::min())) {
		result.setRawBits(std::numeric_limits<int>::min());
	}else {
	    result.setRawBits((int)tempRawBits);
	}
	return result;
}

//To preserve Fixed scale, leftshift numerator by 8, because dividing by Fixed is equivalent to rightshift by 8
//To get closest value rather than floor when using integer division, add/subtract half of denominator
Fixed Fixed::operator/(const Fixed& other) const {
	Fixed result;
	int64_t num = (int64_t)this->value_ << fractionalBits_;
	int64_t denom = (int64_t)other.value_;
	if ((num < 0 && denom > 0) || (num > 0 && denom < 0)) {	//if signs are different, subtract
		num -= denom / 2;
	} else {												//if signs are same, add
		num += denom / 2;
	}
	int64_t tempRawBits = num / denom;
	if (tempRawBits > (std::numeric_limits<int>::max())) {
		result.setRawBits(std::numeric_limits<int>::max());
	} else if (tempRawBits < (std::numeric_limits<int>::min())) {
		result.setRawBits(std::numeric_limits<int>::min());
	} else {
	    result.setRawBits((int)tempRawBits);
	}
	return result;
}

//this is pre-increment: adjust the value, and then return it
Fixed& Fixed::operator++() {
	if (value_ < std::numeric_limits<int>::max())
	    value_++;
    return *this;
}

//this is post-increment: make a copy of the old object, then increment value of the original object, return the copy
//the (int) is there simply to give this a different function signature than pre-increment
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    operator++(); //use the previously defined operator for efficiency (useful in more complicated cases than here)
    return temp;
}

Fixed& Fixed::operator--() {
	if (value_ > std::numeric_limits<int>::min())
	    value_--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    operator--();
    return temp;
}
