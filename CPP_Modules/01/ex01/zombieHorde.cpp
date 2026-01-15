#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	if (N < 1) {
		return nullptr;
	}
	Zombie *array = new Zombie[N];
	for (int i = 0; i < N; i++) {
		array[i].setName(name);
	}	
	return array;
}
