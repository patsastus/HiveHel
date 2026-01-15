#ifndef ICE_HPP
#define ICE_HPP
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria{
public:
    Ice();
    Ice(const Ice& other);
    Ice& operator=(const Ice& other);
    ~Ice();
	
	Ice* clone() const override;
	void use(ICharacter& target) override;
};

#endif // ICE_HPP
