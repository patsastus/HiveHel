#include <iostream>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	//AAnimal a; //this will throw a compiler error bevause AAnimal contains a pure virtual function;
	AAnimal* dog = new Dog();
	AAnimal* cat = new Cat();	
	std::cout << "AAnimal 'dog' has type " << dog->getType() << " and makes sound ";
	dog->makeSound();
	std::cout << "AAnimal 'cat' has type " << cat->getType() << " and makes sound ";
	cat->makeSound();
	delete dog;
	delete cat;

	return 0;
}
