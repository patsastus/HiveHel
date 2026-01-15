#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_("Unicorn"){
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type) : type_(type){
	std::cout << "WrongAnimal parametrized constructor called with type "<<type_ << std::endl;

}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type_(other.type_){
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) {
        this->type_ = other.type_;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called @" << this << std::endl;
}

void WrongAnimal::makeSound() const{
	std::cout << "Nay" << std::endl;
}

std::string WrongAnimal::getType() const{
	return type_;
}

