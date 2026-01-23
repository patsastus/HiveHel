#include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
 	return *this;
}

Intern::~Intern() {
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target){
	typedef AForm *(Intern::*FunctionPtr)(std::string const &);
	struct FormMap {
		std::string name;
		FunctionPtr func;
	};

	FormMap knownForms[] = {
		{"shrubbery creation", &Intern::makeShrubberyCreation},
		{"robotomy request", &Intern::makeRobotomyRequest},
		{"presidential pardon", &Intern::makePresidentialPardon}
	};
	int numForms  = 3;

	for (int i = 0; i < numForms; ++i){
		if (knownForms[i].name == formName) {
			AForm *form = (this->*knownForms[i].func)(target);
			std::cout << "Intern creates "<< *form << std::endl;
			return form;
		}
	}
	std::cout << "This lowly intern doesn't know the requested form: " << formName << std::endl;
	return nullptr;
}

AForm *Intern::makePresidentialPardon(std::string const &target){
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotomyRequest(std::string const &target){
	return new RobotomyRequestForm(target);
}

AForm *Intern::makeShrubberyCreation(std::string const &target){
	return new ShrubberyCreationForm(target);
}

