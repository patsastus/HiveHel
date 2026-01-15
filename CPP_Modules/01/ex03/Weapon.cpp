#include "Weapon.hpp"

Weapon::Weapon(std::string type){
	type_ = type;
}

Weapon::~Weapon(){

}

const std::string& Weapon::getType(){
	return type_;
}

void Weapon::setType(const std::string &newType){
	type_ = newType;
}

