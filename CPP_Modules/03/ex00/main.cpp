#include <iostream>
#include "ClapTrap.hpp"
#define COLOR_GREEN "\033[32m"
#define COLOR_RESET "\033[0m" 

int main() {

	std::cout << COLOR_GREEN << "Creating come traps..." << COLOR_RESET << std::endl << std::endl;
	ClapTrap jeff("Jeff");
	ClapTrap *anon = new ClapTrap();
	ClapTrap copy = *anon; //this actually calls copy constructor, not assignment;
	ClapTrap assigned;
	assigned = jeff;
	
	std::cout << std::endl << COLOR_GREEN << "Testing basic functionality..." << COLOR_RESET << std::endl << std::endl;
	jeff.attack("some stranger");
	anon->takeDamage(5);
	jeff.attack("some other stranger");
	anon->takeDamage(6);
	jeff.attack("some other stranger");
	
	std::cout << std::endl << COLOR_GREEN <<  "Testing health == 0" << COLOR_RESET <<  std::endl << std::endl;
	anon->takeDamage(6);
	anon->attack("Steve");
	anon->beRepaired(5);

	std::cout << std::endl <<  COLOR_GREEN << "Running energy to 0, and testing energy == 0" << COLOR_RESET << std::endl << std::endl;
	for (unsigned int i = 0; i < 8; ++i) {
		jeff.beRepaired(i);
	}
	jeff.attack("Jeff");
	jeff.takeDamage(20);

	std::cout << std::endl <<  COLOR_GREEN << "Testing energy == 0 and health == 0" << COLOR_RESET << std::endl << std::endl;
	jeff.takeDamage(20);
	jeff.attack("99");

	delete anon;

	std::cout << std::endl <<  COLOR_GREEN << "Testing limits..." << COLOR_RESET << std::endl << std::endl;
	ClapTrap limits;
	limits.beRepaired(std::numeric_limits<unsigned int>::max());
	limits.takeDamage(std::numeric_limits<unsigned int>::max());
	limits.attack("the sky");
	return 0;
}

