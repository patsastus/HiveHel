#include "Character.hpp"

Character::Character() : ICharacter(), name_("Default") {
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const std::string &name) :  ICharacter(), name_(name) { 
	std::cout << "Character parametrized constructor called with name " << name_ << std::endl;
}

Character::Character(const Character& other) : ICharacter(other), name_(other.name_) {
	for (int i = 0; i < 4; ++i){
		if (other.inventory_[i]) {
			inventory_[i] = other.inventory_[i]->clone();
		}
		this->inUse_[i] = other.inUse_[i];
	}
	this->name_ = other.name_;
	std::cout << "Character copy constructor called" << std::endl;
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i){
			if (this->inventory_[i]) {
				delete (this->inventory_[i]);
				this->inventory_[i] = nullptr;
			}
			if (other.inventory_[i]) {
				this->inventory_[i] = other.inventory_[i]->clone();
			}
			this->inUse_[i] = other.inUse_[i];
		}
    }
	this->name_ = other.name_;
    return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; ++i){
		if (inventory_[i])
			delete inventory_[i];
	}
	std::cout << "Character destructor called @"<< this << std::endl;
}

std::string const & Character::getName() const{
	return name_;
}

void Character::equip(AMateria* m){
	if (!m) //ignore nullptrs
		return;
	for (int i = 0; i < 4; ++i){ //first check if this exact pointer is already stored
		if (m == inventory_[i])
			return;
	}
	for (int i = 0; i < 4; ++i){
		if (!inUse_[i]) {
			if (inventory_[i])
				delete inventory_[i];
			inventory_[i] = m;
			inUse_[i] = true;
			std::cout << name_ << " equipped Materia " << m->getType() << " into slot " << i << std::endl;
			return;
		}
	}
	std::cout << name_ << " couldn't equip Materia "<< m->getType() << std::endl;
}

void Character::unequip(int idx){
	if (idx >= 0 && idx <= 3 && inUse_[idx]){
		std::cout << name_ << " unequipped Materia "<< inventory_[idx]->getType();
		std::cout<< " in slot " << idx << std::endl;
		inUse_[idx] = false;
	} else {
		std::cout << name_ << " couldn't unequip Materia in slot " << idx << std::endl;
	}
}

void Character::use(int idx, ICharacter& target){
	if (idx >= 0 && idx <= 3 && inUse_[idx]) 
		inventory_[idx]->use(target);
}

