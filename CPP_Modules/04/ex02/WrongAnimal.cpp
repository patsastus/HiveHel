#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_("Unicorn"){
}

WrongAnimal::WrongAnimal(const std::string type) : type_(type){
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) {
        this->type_ = other.type_;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
}

void WrongAnimal::makeSound() const{
	std::cout << "Nay" << std::endl;
}

std::string WrongAnimal::getType() const{
	return type_;
}

