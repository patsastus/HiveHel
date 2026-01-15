#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource() {	
	std::cout << "IMateriaSource default constructor called" << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource& other) {
	std::cout << "IMateriaSource copy constructor called" << std::endl;
	(void)other;
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource& other) {
	(void)other;
	return *this;
}

IMateriaSource::~IMateriaSource() {
	std::cout << "IMateriaSource destructor called @" << this << std::endl;
}
