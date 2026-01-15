#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& other);
    ~MateriaSource();

	virtual void learnMateria(AMateria* mat) override;
	virtual AMateria* createMateria(std::string const & type) override;

private: 
	AMateria *knownMateria_[4];
	int used_;
};

#endif // MATERIASOURCE_HPP
