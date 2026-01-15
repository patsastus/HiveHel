#ifndef HUMANA_HPP
#define HUMANA_HPP
#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon &w);
		~HumanA();
		void attack();
	
	private:
		Weapon &weapon_;
		std::string	name_;
		const std::string &getName();
};
#endif
