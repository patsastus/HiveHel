#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		~HumanB();
		void attack();
		void setWeapon(Weapon &w);
	
	private:
		Weapon *weapon_;
		std::string	name_;
		const std::string &getName();
};
#endif
