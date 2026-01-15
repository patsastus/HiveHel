#ifndef CURE_HPP
#define CURE_HPP
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria{
public:
    Cure();
    Cure(const Cure& other);
    Cure& operator=(const Cure& other);
    ~Cure();
	
	Cure* clone() const override;
	void use(ICharacter& target) override;
};

#endif // CURE_HPP
