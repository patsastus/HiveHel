#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat def;
	std::cout << "Default Bureaucrat : "<< def << std::endl;
	Bureaucrat max("Chad", 1);
	std::cout << "Maximal Bureaucrat : "<< max << std::endl;

	std::cout << "Testing creation of forms with illegal grades"<< std::endl << std::endl;
	{
		try {
			Form f("business", 0, 12);
		}
		catch (const Form::GradeTooHighException &e){
			std::cout << "Caught exception : "<< e.what() << std::endl;
		}
	}
	{
		try {
			Form f("business", 151, 12);
		}
		catch (const Form::GradeTooLowException &e){
			std::cout << "Caught exception : "<< e.what() << std::endl;
		}
	}
	{
		try {
			Form f("business", 12, 0);
		}
		catch (const Form::GradeTooHighException &e){
			std::cout << "Caught exception : "<< e.what() << std::endl;
		}
	}
	{
		try {
			Form f("business", 12, 151);
		}
		catch (const Form::GradeTooLowException &e){
			std::cout << "Caught exception : "<< e.what() << std::endl;
		}
	}

	std::cout << std::endl << "Testing signing with correct and incorrect bureaucrats" << std::endl;
	{
		Form f("Business license", 149, 149);
		std::cout << f << std::endl;
		def.signForm(f);
		max.signForm(f);
	}
	return 0;
}
