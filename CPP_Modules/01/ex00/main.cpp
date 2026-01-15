#include "Zombie.hpp"

int main()
{
	Zombie first = Zombie();
	Zombie *second = newZombie("Pointy");
	randomChump("Rando");
	first.announce();
	second->announce();
	delete second;
	return (0);
}
