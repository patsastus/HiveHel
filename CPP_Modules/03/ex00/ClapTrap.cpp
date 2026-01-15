#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name_("Default"), hitPoints_(10), energyPoints_(10), attackDamage_(0){
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : name_(name), hitPoints_(10), energyPoints_(10), attackDamage_(0){	
	std::cout << "ClapTrap parametrized constructor called with name " << name_ << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name_(other.name_), hitPoints_(other.hitPoints_), energyPoints_(other.energyPoints_), attackDamage_(other.attackDamage_){
	std::cout << "ClapTrap copy constructor called with name " << name_ << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap copy assignment operator called with name " << other.name_ << std::endl;
    if (this != &other) {
        this->name_ = other.name_;
        this->hitPoints_ = other.hitPoints_;
        this->energyPoints_ = other.energyPoints_;
        this->attackDamage_ = other.attackDamage_;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
   	std::cout << "ClapTrap '" << name_ << "' destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target){
	if (energyPoints_ > 0 && hitPoints_ > 0) {
		std::cout << "ClapTrap '" << name_ << "' attacks " << target ;
		std::cout << ", causing " << attackDamage_ << " points of damage!" << std::endl;
		energyPoints_--;
	} else if (hitPoints_ > 0 && energyPoints_ == 0) {
		std::cout << "ClapTrap '" << name_ << "' has no energy to do anything" << std::endl;
	} else if (hitPoints_ == 0) {
		std::cout << "ClapTrap '" << name_ << "' is broken and can't do anything" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount){
	if (hitPoints_ > 0) {
		unsigned int actual;
		if (amount < hitPoints_)
			actual = amount;
		else
			actual = hitPoints_;
		std::cout << "ClapTrap '" << name_ << "' takes " << actual << " points of damage!" << std::endl;
		hitPoints_ -= actual;
	} else {
		std::cout << "ClapTrap '" << name_ << "' is broken and attacking them doesn't do anything" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (energyPoints_ > 0 && hitPoints_ > 0) {
		unsigned int actual;
		if (hitPoints_ <= std::numeric_limits<unsigned int>::max() - amount){
			hitPoints_ += amount;
			actual = amount;
		} else {
			actual = std::numeric_limits<unsigned int>::max() - hitPoints_;
			hitPoints_ = std::numeric_limits<unsigned int>::max();
		}
		std::cout << "ClapTrap '" << name_ << "' regained " << actual << " hit points, new total: " << hitPoints_ << std::endl;
		energyPoints_--;
	} else if (hitPoints_ > 0 && energyPoints_ == 0) {
		std::cout << "ClapTrap '" << name_ << "' has no energy to do anything" << std::endl;
	} else if (hitPoints_ == 0) {
		std::cout << "ClapTrap '" << name_ << "' is broken and can't do anything" << std::endl;
	}
}
