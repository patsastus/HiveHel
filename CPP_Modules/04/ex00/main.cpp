#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#define COLOR_GREEN "\033[32m"
#define COLOR_RESET "\033[0m" 

int main() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << COLOR_GREEN << "Testing basic functionality " << COLOR_RESET << std::endl;
	std::cout << "Animal of type " << j->getType() << " " << std::endl << "makes sound " ;
	j->makeSound();
	std::cout << "Animal of type " << i->getType() << " " << std::endl << "makes sound " ;
	i->makeSound();
	std::cout << "Animal of type " << meta->getType() << " " << std::endl << "makes sound " ;
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	std::cout << COLOR_GREEN << "Testing WrongAnimal and WrongCat functionality " << COLOR_RESET << std::endl;

	const WrongCat *kat = new WrongCat();
	const WrongAnimal *ani = kat;
	const WrongAnimal *base = new WrongAnimal();

	std::cout << "WrongCat has type " << kat->getType() << " " << std::endl << "makes sound " ;
	kat->makeSound();
	std::cout << "Upcast WrongAnimal has type " << ani->getType() << " " << std::endl << "makes sound " ;
	ani->makeSound();
	std::cout << "Baseline WrongAnimal has type " << base->getType() << " " << std::endl << "makes sound " ;
	base->makeSound();

	delete kat;
	delete base;

	return 0;
}
