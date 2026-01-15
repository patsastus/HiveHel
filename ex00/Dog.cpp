#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other){
   	std::cout << "Cat default constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        this->type_ = other.type_;
    }
    return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called @" << this << std::endl;
}

void Dog::makeSound() const{
	std::cout << "Woof" << std::endl;
}

