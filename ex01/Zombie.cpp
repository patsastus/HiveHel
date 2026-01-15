#include "Zombie.hpp"

Zombie::Zombie(void) {
	this->name_ = "Daffy";
}

Zombie::Zombie(std::string name) {
	this->name_ = name;
}

Zombie::~Zombie(void) {
	std::cout << "Zombie named '" << this->name_ << "' destructed." << std::endl;
}

void Zombie::announce(void) {
	std::cout << this->name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	this->name_ = name;
}
