#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(){
	std::cout << "DiamondTrap default constructor called" << std::endl;
    name_ = "Default";
	hitPoints_ = FragTrap::hitPoints_;
	energyPoints_ = ScavTrap::energyPoints_;
	attackDamage_ = FragTrap::attackDamage_;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(){
	std::cout << "DiamondTrap parametrized constructor called with name " << name << std::endl;
    name_ = name;
	hitPoints_ = FragTrap::hitPoints_;
	energyPoints_ = ScavTrap::energyPoints_;
	attackDamage_ = FragTrap::attackDamage_;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), ScavTrap(other), FragTrap(other), name_(other.name_) {
	std::cout << "DiamondTrap copy constructor called with name " << other.name_ << std::endl;	
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << "DiamondTrap copy assignment operator called with name " << other.name_ << std::endl;
    if (this != &other) {
        this->name_ = other.name_;
		this->ScavTrap::operator=(other);
		this->FragTrap::operator=(other);
    }
    return *this;
}

void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(){
	std::cout << "This is DiamondTrap '" << name_ << "', aka ClapTrap '" << ClapTrap::name_ <<"'"<< std::endl;
}


DiamondTrap::~DiamondTrap() { 
   	std::cout << "DiamondTrap '" << name_ << "' destructor called @" << this << std::endl;
}
