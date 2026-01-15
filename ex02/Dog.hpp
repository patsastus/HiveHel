#ifndef DOG_HPP
#define DOG_HPP
#include "AAnimal.hpp"
#include <iostream>
#include "Brain.hpp"

class Dog : public AAnimal{
public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog() override; //requires c++11 : If parent isn't virtual, compiler error

	void makeSound() const override;
	void addThought(const std::string &t);
	void dumpBrain() const;

private:
	Brain *brain_;
};

#endif // DOG_HPP
