#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <string>
#include <iostream>

class WrongAnimal {
public:
    WrongAnimal();
	WrongAnimal(const std::string type);
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    virtual ~WrongAnimal();
	void makeSound() const;	//no virtual this time
	virtual std::string getType() const final; //c++11, can't be overridden:

protected:
	std::string type_;
};

#endif // WRONGANIMAL_HPP
