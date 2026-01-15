#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"


class Character : public ICharacter {
public:
    Character();
	Character(const std::string &name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    ~Character();
	
	std::string const & getName() const override;
	void equip(AMateria* m) override;
	void unequip(int idx) override;
	void use(int idx, ICharacter& target) override;

private:
	std::string	name_;
	AMateria	*inventory_[4] = {nullptr};
	bool		inUse_[4] = {false};
};

#endif // CHARACTER_HPP
