#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void announce( void );

	private:
		std::string name_;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
