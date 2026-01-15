#include "Zombie.hpp"

Zombie::Zombie(void) {
	name_ = "Daffy";
}

Zombie::Zombie(std::string name) {
	name_ = name;
}


Zombie::~Zombie(void) {
	std::cout << "Zombie named '" << name_ << "' destructed" << std::endl;
}

void Zombie::announce(void) {
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


