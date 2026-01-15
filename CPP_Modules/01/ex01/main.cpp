#include "Zombie.hpp"

int main()
{
	int N = 7;
	Zombie *array = zombieHorde(N, "Steve");
	for (int i = 0; i < N; i++) {
		array[i].announce();
	}	
	delete[] array;
	N = 0;
	array = zombieHorde(N, "Jack");
	if (array == nullptr){
		std::cout << "zombieHorde returned a null pointer." << std::endl;
	}
	return (0);
}
