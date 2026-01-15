#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
	std::cout << "FragTrap default constructor called" << std::endl;
	this->hitPoints_ = 100;
	this->energyPoints_ = 100;
	this->attackDamage_ = 30;
}


FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "FragTrap parametrized constructor called with name " << name_ << std::endl;
	this->hitPoints_ = 100;
	this->energyPoints_ = 100;
	this->attackDamage_ = 30;
}


FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called with name " << name_ << std::endl;
	//no class attributes to set, so just the parent copy constructor call is required
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "FragTrap copy assignment operator called with name " << other.name_ << std::endl;
    if (this != &other) {
        this->ClapTrap::operator=(other); //we have no private attributes, so just call the parent assignment operator
	}
    return *this;
}

FragTrap::~FragTrap() {
   	std::cout << "FragTrap '" << name_ << "' destructor called @" << this << std::endl;
}

void FragTrap::highFiveGuys(){
	if (energyPoints_ > 0 && hitPoints_ > 0) {
		std::cout << "FragTrap '" << name_ << "' is holding out it's hand expecting a high five" << std::endl;
	} else if (hitPoints_ > 0 && energyPoints_ == 0) {
		std::cout << "FragTrap '" << name_ << "' has no energy to do anything" << std::endl;
	} else if (hitPoints_ == 0) {
		std::cout << "FragTrap '" << name_ << "' is broken and can't do anything" << std::endl;
	}
}
