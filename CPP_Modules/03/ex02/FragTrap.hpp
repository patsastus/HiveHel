#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public: //intentionally left out attack() overload, as it's not required.
		FragTrap();
		FragTrap(const std::string &name);
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap& other);
		~FragTrap();
		
		void highFiveGuys();
};

#endif // FRAGTRAP_HPP
