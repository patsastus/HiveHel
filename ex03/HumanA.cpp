#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &w) : weapon_(w), name_(name) {
}

HumanA::~HumanA(){
}

void HumanA::attack(){
	std::cout << getName() << " attacks with their " << weapon_.getType() << std::endl;
}

const std::string& HumanA::getName(){
	return name_;
}
