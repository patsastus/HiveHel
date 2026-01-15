#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#define COLOR_GREEN "\033[32m"
#define COLOR_RESET "\033[0m" 

int main() {
	Animal* array[10];
	for(int i = 0; i < 10; ++i){
		if (i < 5)
			array[i] = new Dog();
		else
			array[i] = new Cat();
	}
	std::cout << COLOR_GREEN << "Testing base animals , types of first 5 in array : " << COLOR_RESET << std::endl;
	for (int i = 0; i < 5; ++i){
		std::cout << array[i]->getType() << " ";
	}
	std::cout << "" << std::endl;
	std::cout <<COLOR_GREEN <<  "Testing base animals , types of second 5 in array : " << COLOR_RESET << std::endl;

	for (int i = 5; i < 10; ++i){
		std::cout << array[i]->getType() << " ";
	}
	std::cout << "" << std::endl;

	std::cout << std::endl << COLOR_GREEN << "Testing Brain functionality, base state:"  << COLOR_RESET<< std::endl;
	((Dog*)array[0])->dumpBrain();
	std::cout << COLOR_GREEN << "After adding thought 'foooood':"  << COLOR_RESET<< std::endl;
	((Dog*)array[0])->addThought("foooood");
	((Dog*)array[0])->dumpBrain();
	std::cout << COLOR_GREEN << "After adding thought 'more foooood':"  << COLOR_RESET<< std::endl;
	((Dog*)array[0])->addThought("more foooood");
	((Dog*)array[0])->dumpBrain();

	std::cout <<std::endl << COLOR_GREEN << "Testing deep copy functionality :"  << COLOR_RESET<< std::endl;
	Dog copyDog = *((Dog*)array[0]); //copy is on stack, no need to delete
	Cat copyCat = *((Cat*)array[5]);
	copyDog.addThought("even more food");
	copyCat.addThought("sleeping");
	std::cout << COLOR_GREEN << "Copy of dog has Brain:" << COLOR_RESET<< std::endl;
	copyDog.dumpBrain();
	std::cout << COLOR_GREEN << "Original dog has Brain:" << COLOR_RESET<< std::endl;
	((Dog*)array[0])->dumpBrain();
	std::cout << COLOR_GREEN << "Copy of cat has Brain:" << COLOR_RESET<< std::endl;
	copyCat.dumpBrain();
	std::cout << COLOR_GREEN << "Original cat has Brain:" << COLOR_RESET<< std::endl;
	((Cat*)array[5])->dumpBrain();

	std::cout <<std::endl << COLOR_GREEN << "Exiting..."  << COLOR_RESET<< std::endl;
	for(int i = 0; i < 10; ++i){
		delete 	(Animal *)(array[i]);	//making sure these are treated as Animal*, not Cat* or Dog*
	}
	return 0;
}
