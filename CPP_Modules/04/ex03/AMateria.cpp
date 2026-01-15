#include "AMateria.hpp"

AMateria::AMateria() : type_(""){
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : type_(type){
	std::cout << "AMateria parametrized constructor called with type "<<type_ << std::endl;
}

AMateria::AMateria(const AMateria& other) : type_(other.type_){	
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other) { //do nothing, as subject suggests
	}
    return *this;
}

AMateria::~AMateria() {
	std::cout << "AMateria destructor called @" << this << std::endl;
}

std::string const & AMateria::getType() const{
	return type_;
}

void AMateria::use(ICharacter& target){
	std::cout << "* uses unknown stuff at " << target.getName() << " *" << std::endl;

}
