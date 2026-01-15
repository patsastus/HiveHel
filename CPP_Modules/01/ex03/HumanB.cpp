#include "HumanB.hpp"

HumanB::HumanB(std::string name) : weapon_(NULL), name_(name){
}

HumanB::~HumanB(){
}

void HumanB::attack(){
 	std::cout << getName() << " attacks with their "; 
	if (weapon_) {
		std::cout << weapon_->getType();
	} else {
		std::cout << "imagination";
	}
	std::cout << std::endl;
}

void HumanB::setWeapon(Weapon &w){
	weapon_ = &w;
}

const std::string& HumanB::getName(){
	return name_;
}
