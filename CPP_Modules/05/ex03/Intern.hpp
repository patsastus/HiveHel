#ifndef INTERN_HPP
#define INTERN_HPP
#include <string>
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();
	AForm *makeForm(std::string const &formName, std::string const &target);

private:
	AForm *makePresidentialPardon(std::string const &target);
	AForm *makeRobotomyRequest(std::string const &target);
	AForm *makeShrubberyCreation(std::string const &target);
};

#endif // INTERN_HPP
