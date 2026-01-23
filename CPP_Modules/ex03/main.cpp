#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	AForm *forms[4];
	int numForms = 4;

	std::cout << "Testing Intern'c capability of creating forms"<< std::endl << std::endl;
	Bureaucrat a("David", 5);
	Intern anon;
	forms[0] = anon.makeForm("shrubbery creation", "Hive");
	forms[1] = anon.makeForm("robotomy request", "Evaluator");
	forms[2] = anon.makeForm("presidential pardon", "Student");
	forms[3] = anon.makeForm("finishing studies", "Me");
	for (int i = 0; i < numForms - 1; ++i){ //the last one return nullptr, so no dereferencing that
		a.signAForm(*forms[i]);
		a.executeForm(*forms[i]);
	}
	for (int i = 0; i < numForms; ++i){
		delete forms[i];
	}
	return 0;
}
