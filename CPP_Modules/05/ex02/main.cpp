#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	int grades[] = {145, 137, 45, 5};
	int numGrades = 4;
	AForm *forms[] = {
		new ShrubberyCreationForm("Home"),
	   	new RobotomyRequestForm("Donald"),
	   	new PresidentialPardonForm("Hamburglar")
	};
	int numForms = 3;

	std::cout << "Testing executing unsigned forms"<< std::endl << std::endl;
	{
		Bureaucrat a("Steve", grades[numGrades - 1]);
		for (int i = 0; i < numForms; ++i){
			a.executeForm(*forms[i]);
		}
	}
	
	Bureaucrat a("David", grades[numGrades - 1]);
	for (int i = 0; i < numForms; ++i){
		a.signAForm(*forms[i]);
	}

	std::cout << std::endl << "Testing different bureaucrats executing the forms" << std::endl;
	{
		for (int i = 0; i < numGrades; ++i){
			Bureaucrat test = Bureaucrat("Tester", grades[i]);
			std::cout << "Testing " << test << std::endl;
			for (int j = 0; j < numForms; ++j){
				test.executeForm(*forms[j]);
			}
			std::cout << "" << std::endl;
		}
	}
	
	std::cout << std::endl << "Testing a randomness of RobotomyRequestForm" <<  std::endl;
	for (int i = 0; i < 20; ++i) {
		a.executeForm(*forms[1]);
	}

	for (int i = 0; i < numForms; ++i){
		delete forms[i];
	}
	return 0;
}
