#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat"){
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other){
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        this->type_ = other.type_;
    }
    return *this;
}

WrongCat::~WrongCat() {
}

void WrongCat::makeSound() const{
	std::cout << "CaCaw" << std::endl;
}
