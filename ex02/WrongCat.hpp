#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"
#include <string>
#include <iostream>


class WrongCat : public WrongAnimal {
public:
    WrongCat();
    WrongCat(const WrongCat& other);
    WrongCat& operator=(const WrongCat& other);
    ~WrongCat() override; //requires c++11 : If parent isn't virtual, compiler error

	void makeSound() const; //can't use override, because showing why it and virtual is needed
};

#endif // WRONGCAT_HPP
