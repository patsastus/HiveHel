#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->hitPoints_ = 100;
	this->energyPoints_ = 50;
	this->attackDamage_ = 20;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "ScavTrap parametrized constructor called with name " << name_ << std::endl;
	this->hitPoints_ = 100;
	this->energyPoints_ = 50;
	this->attackDamage_ = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called with name " << name_ << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap copy assignment operator called with name " << other.name_ << std::endl;
    if (this != &other) {
        this->ClapTrap::operator=(other); //we have no private attributes, so just call the parent assignment operator
	}
    return *this;
}

ScavTrap::~ScavTrap() {
   	std::cout << "ScavTrap '" << name_ << "' destructor called @" << this << std::endl;
}

void ScavTrap::attack(const std::string &target){
	if (energyPoints_ > 0 && hitPoints_ > 0) {
		std::cout << "ScavTrap '" << name_ << "' attacks " << target ;
		std::cout << ", causing " << attackDamage_ << " points of damage!" << std::endl;
		energyPoints_--;
	} else if (hitPoints_ > 0 && energyPoints_ == 0) {
		std::cout << "ScavTrap '" << name_ << "' has no energy to do anything" << std::endl;
	} else if (hitPoints_ == 0) {
		std::cout << "ScavTrap '" << name_ << "' is broken and can't do anything" << std::endl;
	}
}

void ScavTrap::guardGate(){
	if (energyPoints_ > 0 && hitPoints_ > 0) {
		std::cout << "ScavTrap '" << name_ << "' has entered Gatekeeper mode" << std::endl;
	} else if (hitPoints_ > 0 && energyPoints_ == 0) {
		std::cout << "ScavTrap '" << name_ << "' has no energy to do anything" << std::endl;
	} else if (hitPoints_ == 0) {
		std::cout << "ScavTrap '" << name_ << "' is broken and can't do anything" << std::endl;
	}
}
