#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap { //virtual needed to ensure only one ClapTrap used in DiamondTrap
	public: 
		FragTrap();
		FragTrap(const std::string &name);
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap& other);
		~FragTrap();
		
		void highFiveGuys();
};

#endif // FRAGTRAP_HPP
