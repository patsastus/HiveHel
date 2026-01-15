#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): IMateriaSource(), used_(0) {	
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) : IMateriaSource(other), used_(other.used_){
	std::cout << "MateriaSource copy constructor called" << std::endl;
    for (int i = 0; i < used_; ++i) {
		knownMateria_[i] = other.knownMateria_[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
		this->used_ = 0;
		for (int i = 0; i < 4; ++i){
			if (this->knownMateria_[i]) {
				delete (this->knownMateria_[i]); 
			}
			if (other.knownMateria_[i]) {
				this->learnMateria(other.knownMateria_[i]);
			}
		}
    }
    return *this;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor called @" << this << std::endl;
	for (int i = 0; i < used_; ++i) {
		delete knownMateria_[i];
	}
}

void MateriaSource::learnMateria(AMateria* mat){
	if (mat && used_ < 4) {
		knownMateria_[used_++] = mat->clone();		
		std::cout << "Source learned materia " << mat->getType() << " into slot " << used_ - 1 << std::endl;
	} else if (!mat) {
		std::cout << "Source can't learn nullptr materia" << std::endl;
	} else {
		std::cout << "Source can't learn any more materia" << std::endl;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < used_; ++i){
		if (knownMateria_[i]->getType() == type) {
			return knownMateria_[i]->clone();
		}
	}
	return nullptr;
}

