#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
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


	std::cout << std::endl << "Testing OCF constructors and copy assignment" << std::endl; 
	Form f("Business license", 149, 149);
	Form form = f;
	std::cout << "Original form: "<<f<< ", copy: "<<form << std::endl; 
	Form toBeAssigned("Different form", 1, 1); 
	toBeAssigned = f;
	std::cout << "Attempted assignment: " << toBeAssigned << std::endl << std::endl; 	//The only mutable member of Form is isSigned_, 
																				//so allowing assignment would allow Forms to be signed
																				//without proper Bureaucrat approval

	std::cout << std::endl << "Testing signing with correct and incorrect bureaucrats" << std::endl;
	Bureaucrat def;
	std::cout << "Default Bureaucrat : "<< def << std::endl;
	Bureaucrat max("Maximus", 1);
	std::cout << "Maximal Bureaucrat : "<< max << std::endl;

	std::cout << f << std::endl;
	def.signForm(f);
	max.signForm(f);

	std::cout << std::endl << "Testing copying a signed form" << std::endl; 
	Form newCopy(f);
	std::cout << std::endl << "Original form: "<<f<< ", old copy: "<<form << ", new copy: "<< newCopy <<std::endl << std::endl; 
	return 0;
}
