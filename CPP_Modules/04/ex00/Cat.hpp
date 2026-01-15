#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include <iostream>


class Cat : public Animal {
public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat() override; //requires c++11 : If parent isn't virtual, compiler error

	void makeSound() const override;
};

#endif // CAT_HPP
