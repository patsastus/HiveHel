#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#define COLOR_GREEN "\033[32m"
#define COLOR_RESET "\033[0m" 

int main() {
	{
		std::cout << COLOR_GREEN << "Creating some traps..." <<COLOR_RESET << std::endl << std::endl;
		ScavTrap jeff("Jeff");
		ScavTrap bob("Bob");
		std::cout << std::endl;
		ScavTrap *anon = new ScavTrap();
		std::cout << std::endl;
		bob = jeff;
		std::cout << std::endl;
		ScavTrap copy(*anon);

		std::cout << std::endl <<COLOR_GREEN << "Testing basic functionality..." <<COLOR_RESET <<  std::endl << std::endl;
		jeff.attack("some stranger");
		anon->takeDamage(5);
		jeff.attack("some other stranger");
		anon->takeDamage(6);
		jeff.attack("some other stranger");
		anon->takeDamage(6);
		anon->attack("Steve");
		anon->beRepaired(5);
		for (unsigned int i = 0; i < 48; ++i) {
			anon->beRepaired(i);
		}

		std::cout << std::endl << COLOR_GREEN <<"Testing explicitly calling parent class attack function..." << COLOR_RESET << std::endl << std::endl;
		jeff.attack("Jeff");
		jeff.ClapTrap::attack("the air");

		std::cout << std::endl << COLOR_GREEN <<"Testing guardGate() functionality..." << COLOR_RESET << std::endl << std::endl;
		jeff.guardGate();
		jeff.takeDamage(5000);
		jeff.guardGate();
		anon->guardGate();
		delete anon;
	}

	std::cout << std::endl << COLOR_GREEN <<"Extras and virtual destructor..." << COLOR_RESET << std::endl << std::endl;
	ScavTrap anon("nn");
	std::cout << "'anon' is at" << &anon << std::endl;
	ClapTrap *test = new ScavTrap("Test");
	std::cout << "'test' is at" << test << std::endl;
	ClapTrap *copy = new ClapTrap(*test);
	std::cout << "'copy' is at" << copy << std::endl;

	std::cout << COLOR_GREEN <<"Deleting 'test'" << COLOR_RESET << std::endl;
	delete test;
	std::cout << COLOR_GREEN <<"Deleting 'copy'" << COLOR_RESET << std::endl;
	delete copy;
	std::cout << COLOR_GREEN << "Exiting main" << COLOR_RESET << std::endl;
	return 0;
}

