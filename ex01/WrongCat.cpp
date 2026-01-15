#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat"){
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other){
   	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        this->type_ = other.type_;
    }
    return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called @" << this << std::endl;
}

void WrongCat::makeSound() const{
	std::cout << "CaCaw" << std::endl;
}
