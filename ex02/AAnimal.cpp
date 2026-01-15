#include "AAnimal.hpp"

AAnimal::AAnimal() : type_(""){
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string type ): type_(type){
	std::cout << "AAnimal parametrized constructor called with type "<< type_ << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type_(other.type_){
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    if (this != &other) {
        this->type_ = other.type_;
    }
    return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called @" << this << std::endl;
}

std::string AAnimal::getType() const{
	return type_;
}

