#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include <iostream>
#include <limits>

class ClapTrap {
	public:
		ClapTrap();
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		virtual ~ClapTrap(); 						//virtual ensures derived destructors are called even if pointer was cast to base class
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:
		std::string		name_;
		unsigned int 	hitPoints_;
		unsigned int 	energyPoints_;
		unsigned int	attackDamage_;
};

#endif // CLAPTRAP_HPP
