#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
#include <iostream>

class Animal {
public:
    Animal();
	Animal(const std::string type);
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();
	virtual void makeSound() const;
	virtual std::string getType() const final; //c++11, can't be overridden:

protected:
	std::string type_;
};

#endif // ANIMAL_HPP
