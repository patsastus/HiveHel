#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"
#include <iostream>


class WrongCat : public WrongAnimal {
public:
    WrongCat();
    WrongCat(const WrongCat& other);
    WrongCat& operator=(const WrongCat& other);
    ~WrongCat() override; //requires c++11 : If parent isn't virtual, compiler error

	void makeSound() const; 
};

#endif // WRONGCAT_HPP
