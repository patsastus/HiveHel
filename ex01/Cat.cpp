#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
	std::cout << "Cat default constructor called" << std::endl;
	brain_ = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other){
    std::cout << "Cat copy constructor called" << std::endl;
	brain_ = new Brain(*(other.brain_)); //brain_ is a pointer, constructor wants reference
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        this->Animal::operator=(other);
		*(this->brain_) = *(other.brain_);
    }
    return *this;
}

Cat::~Cat() {
	delete brain_;
	std::cout << "Cat destructor called @" << this << std::endl;
}

void Cat::addThought(const std::string &t){
	brain_->addThought(t);
}

void Cat::dumpBrain() const{
	brain_->dump();
}

void Cat::makeSound() const{
	std::cout << "Miau" << std::endl;
}
