#include "ICharacter.hpp"

ICharacter::ICharacter() {
	std::cout << "ICharacter default constructor called" << std::endl;
}

ICharacter::ICharacter(const ICharacter& other) { 
	(void)other;
	std::cout << "ICharacter copy constructor called" << std::endl;
}

ICharacter& ICharacter::operator=(const ICharacter& other) {
    if (this != &other) {
    }
    return *this;
}

ICharacter::~ICharacter() {
	std::cout << "ICharacter destructor called @" << this << std::endl;
}
