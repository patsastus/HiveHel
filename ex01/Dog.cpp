#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout << "Dog default constructor called" << std::endl;
	brain_ = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other){
   	std::cout << "Dog copy constructor called" << std::endl;
	brain_ = new Brain(*(other.brain_)); 
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        this->Animal::operator=(other);
		*(this->brain_) = *(other.brain_);
    }
    return *this;
}

Dog::~Dog() {
	delete brain_;
	std::cout << "Dog destructor called @" << this << std::endl;
}

void Dog::makeSound() const{
	std::cout << "Woof" << std::endl;
}

void Dog::addThought(const std::string &t){
	brain_->addThought(t);
}

void Dog::dumpBrain() const{
	brain_->dump();
}
