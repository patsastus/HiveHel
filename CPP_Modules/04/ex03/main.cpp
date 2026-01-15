#include <iostream>
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#define COLOR_GREEN "\033[32m"
#define COLOR_RESET "\033[0m" 

int main() {
	{
		std::cout << COLOR_GREEN << "** Testing basic functionality **" << COLOR_RESET << std::endl;
		IMateriaSource* src = new MateriaSource();
		AMateria* ice = new Ice();
		src->learnMateria(ice);
		AMateria* cure = new Cure();
		src->learnMateria(cure);
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob); //shouldn't output anything, but no errors;
		std::cout << std::endl << COLOR_GREEN << "** Testing equip/unequip **"<< COLOR_RESET  << std::endl;
		me->unequip(0);
		me->unequip(0); //should fail gracefully
		me->unequip(10);
		me->use(0, *bob); //shouldn't output anything
		me->use(1, *me);  //should still work
		me->equip(src->createMateria("cure")); //should go into slot 0
		me->use(0, *bob); 

		delete bob;
		delete me;
		delete src;
		delete cure;
		delete ice;
	}

	{
		std::cout << std::endl << COLOR_GREEN << "** Testing creating non-learned Materia **" << COLOR_RESET  << std::endl;
		MateriaSource* base = new MateriaSource();
		AMateria *cure = new Cure();
		base->learnMateria(cure);
		AMateria *tmp = base->createMateria("Coca-Cola");
		if (tmp) {
			std::cout << "Incorrectly returned a material" << std::endl;
		} else {
			std::cout << "Returned nullptr as expected" << std::endl;
		}
		delete tmp;
		tmp = base->createMateria("ice");
		if (tmp) {
			std::cout << "Incorrectly returned a material" << std::endl;
		} else {
			std::cout << "Returned nullptr as expected" << std::endl;
		}
		delete tmp;
		delete base;
		delete cure;
	}

	{
		//testing copy constructor functionality
		std::cout << COLOR_GREEN <<  "** Testing copy constructors**" << COLOR_RESET << std::endl;
		Ice* ice = new Ice(); 			//copy constructor requires an Ice object, not AMateria
		AMateria* ice2 = new Ice(*ice);
		Cure* cure = new Cure(); 		//copy constructor requires an Cure object
		AMateria* cure2 = new Cure(*cure);
		MateriaSource* base = new MateriaSource();
		base->learnMateria(cure);
		IMateriaSource* copySrc = new MateriaSource(*base);
		Character* dude = new Character("dude");
		dude->equip(cure);
		ICharacter* copyMe = new Character(*dude);

		std::cout << std::endl << COLOR_GREEN <<  "** Testing overflows of MateriaSource **" << COLOR_RESET << std::endl;
		copySrc->learnMateria(ice);
		copySrc->learnMateria(ice2);
		copySrc->learnMateria(cure);
		copySrc->learnMateria(cure2);		//should "overflow" == do nothing
										
		std::cout << std::endl << COLOR_GREEN <<  "** Testing overflows of Character **" << COLOR_RESET << std::endl;
		copyMe->equip(copySrc->createMateria("cure"));
		copyMe->equip(copySrc->createMateria("cure"));
		copyMe->equip(copySrc->createMateria("cure"));
		AMateria *tmp = copySrc->createMateria("cure");
		copyMe->equip(tmp); //should fail gracefully

		delete tmp;
		delete dude;
		delete base;
		delete copySrc;
		delete copyMe;
		delete ice;
		delete ice2;
		delete cure2;
	}
	return 0;
}
