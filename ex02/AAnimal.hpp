#ifndef AANIMAL_HPP
#define AANIMAL_HPP
#include <string>
#include <iostream>

class AAnimal {
public:
    AAnimal();
	AAnimal(const std::string type);
    AAnimal(const AAnimal& other);
    AAnimal& operator=(const AAnimal& other);
    virtual ~AAnimal();
	virtual void makeSound() const = 0; //pure virtual function makes class uninstantiable. Derived class has to implement it
	virtual std::string getType() const final;

protected:
	std::string type_;
};

#endif // AANIMAL_HPP
