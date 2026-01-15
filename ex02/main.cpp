#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#define COLOR_GREEN "\033[32m"
#define COLOR_RESET "\033[0m" 

int main() {
	{
		std::cout << COLOR_GREEN << "Creating some traps..." << COLOR_RESET << std::endl << std::endl;
		FragTrap jeff("Jeff");
		FragTrap steve("Steve");
		std::cout << std::endl;
		FragTrap *anon = new FragTrap();
		std::cout << std::endl;
		steve = jeff;
		std::cout << std::endl;
		FragTrap copy = FragTrap(*anon);


		std::cout << COLOR_GREEN << std::endl << "Testing basic functionality..." << COLOR_RESET << std::endl << std::endl;
		jeff.attack("some stranger");
		anon->takeDamage(5);
		jeff.attack("some other stranger");
		anon->takeDamage(6);
		jeff.attack("some other stranger");
		anon->takeDamage(6);

		anon->attack("Steve");
		anon->beRepaired(5);
		for (unsigned int i = 0; i < 98; ++i) {
			anon->beRepaired(i);
		}

		std::cout << COLOR_GREEN << std::endl << "Testing explicitly calling parent class attack function..." << COLOR_RESET << std::endl << std::endl;
		jeff.attack("Jeff");
		jeff.ClapTrap::attack("the air");

		std::cout << COLOR_GREEN << std::endl << "Testing highFiveGuys() functionality..." << COLOR_RESET << std::endl << std::endl;
		jeff.highFiveGuys();
		jeff.takeDamage(5000);
		jeff.highFiveGuys();
		anon->highFiveGuys();
		delete anon;
	}

	std::cout << COLOR_GREEN << std::endl << "Extras and virtual destructor..." << COLOR_RESET << std::endl << std::endl;
	FragTrap anon;
	std::cout << "'anon' is at" << &anon << std::endl;
	ClapTrap *test = new FragTrap();
	std::cout << "'test' is at" << test << std::endl;
	ClapTrap *copy = new ClapTrap(*test);
	std::cout << "'copy' is at" << copy << std::endl;

	std::cout << COLOR_GREEN << "Deleting 'test'" << COLOR_RESET << std::endl;
	delete test;
	std::cout << COLOR_GREEN << "Deleting 'copy'" << COLOR_RESET << std::endl;
	delete copy;
	std::cout << COLOR_GREEN << "Exiting main" << COLOR_RESET << std::endl;
	return 0;
}

