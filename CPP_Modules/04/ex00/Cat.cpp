#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other){
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        this->type_ = other.type_;
    }
    return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called @" << this << std::endl;
}

void Cat::makeSound() const{
	std::cout << "Miau" << std::endl;
}
