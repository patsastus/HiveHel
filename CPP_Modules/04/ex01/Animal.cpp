#include "Animal.hpp"

Animal::Animal() : type_("animal"){
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string type ): type_(type){
	std::cout << "Animal parametrized constructor called with type "<< type_ << std::endl;
}

Animal::Animal(const Animal& other) :type_(other.type_){
 	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        this->type_ = other.type_;
    }
    return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called @" << this << std::endl;
}

void Animal::makeSound() const{
	std::cout << "** <Generic animal noises> **" << std::endl;
}

std::string Animal::getType() const{
	return type_;
}

