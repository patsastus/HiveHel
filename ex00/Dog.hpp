#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include <iostream>

class Dog : public Animal{
public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog() override; //requires c++11 : If parent isn't virtual, compiler error

	void makeSound() const override;
};

#endif // DOG_HPP
