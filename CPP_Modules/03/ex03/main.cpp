#include <iostream>
#include "DiamondTrap.hpp"
#define COLOR_GREEN "\033[32m"
#define COLOR_RESET "\033[0m" 
#define COLOR_CYAN "\033[36m"

int main() {
	{
		std::cout << COLOR_GREEN << "Creating some traps..." << COLOR_RESET << std::endl << std::endl;
		DiamondTrap jeff("Jeff");
		std::cout << "" << std::endl;
		DiamondTrap steve("Steve");
		std::cout << std::endl;
		DiamondTrap *anon = new DiamondTrap();
		std::cout << std::endl;
		steve = jeff;
		std::cout << std::endl;
		DiamondTrap copy = DiamondTrap(*anon);

		std::cout << COLOR_GREEN << std::endl << "Testing basic functionality..." << COLOR_RESET << std::endl << std::endl;
		jeff.attack("some stranger");
		anon->takeDamage(5);
		jeff.attack("some other stranger");
		anon->takeDamage(6);
		jeff.attack("some other stranger");
		anon->takeDamage(6);

		anon->attack("Steve");
		anon->beRepaired(5);
		for (unsigned int i = 0; i < 99; ++i) {
			anon->beRepaired(i);
		}

		std::cout << COLOR_GREEN << std::endl << "Testing explicitly calling attack function for the different classes..." << COLOR_RESET << std::endl << std::endl;
		std::cout << COLOR_CYAN << "//DiamondTrap attack(), should be ScavTrap's attack()" << COLOR_RESET << std::endl;
		jeff.attack("Jeff");
		std::cout << COLOR_CYAN << "//ClapTrap attack(), should be ClapTrap's" << COLOR_RESET << std::endl;
		jeff.ClapTrap::attack("the air");
		std::cout << COLOR_CYAN << "//ScavTrap attack(), should be ScavTrap's" << COLOR_RESET << std::endl;
		jeff.ScavTrap::attack("the sky");
		std::cout << COLOR_CYAN << "//FragTrap attack(), because that class doesn't implement attack, should fall back to ClapTrap's" << COLOR_RESET << std::endl;
		jeff.FragTrap::attack("the clouds");

		std::cout << COLOR_GREEN << std::endl << "Testing calling the 'hidden' functions of the inherited classes" << COLOR_RESET << std::endl << std::endl;
		jeff.guardGate();
		jeff.highFiveGuys();

		std::cout << COLOR_GREEN << std::endl << "Testing whoAmI() functionality..." << COLOR_RESET << std::endl << std::endl;

		std::cout << COLOR_CYAN << "//jeff and steve=jeff" << COLOR_RESET << std::endl;
		jeff.whoAmI();
		steve.whoAmI();

		std::cout << COLOR_CYAN << "//Default and copy of default" << COLOR_RESET << std::endl;
		anon->whoAmI();
		copy.whoAmI();
		delete anon;
	}

	std::cout << COLOR_GREEN << std::endl << "Extras and virtual destructor..." << COLOR_RESET << std::endl << std::endl;
	DiamondTrap anon("nn");
	std::cout << "'anon' is at" << &anon << std::endl;
	ClapTrap *test = new DiamondTrap("Testing");
	std::cout << "'test' is at" << test << std::endl;

	std::cout << COLOR_GREEN << "Deleting 'test'" << COLOR_RESET << std::endl;
	delete test;
	std::cout << COLOR_GREEN << "Exiting main" << COLOR_RESET << std::endl;
	return 0;
}

