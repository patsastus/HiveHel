#include "Ice.hpp"

Ice::Ice() : AMateria("ice"){
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other){
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
    if (this != &other) {
        this->AMateria::operator=(other);
    }
    return *this;
}

Ice::~Ice() {
	std::cout << "Ice destructor called @" << this << std::endl;
}

Ice* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

