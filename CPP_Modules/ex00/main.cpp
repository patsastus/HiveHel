#include <iostream>
#include "Bureaucrat.hpp"

int main() {
	std::cout << std::endl << "Testing OCF constructors and copy assignment overload"<< std::endl << std::endl;
	Bureaucrat def;
	std::cout << "Default Bureaucrat : "<< def << std::endl;
	Bureaucrat max("Maximus", 1);
	std::cout << "Maximal Bureaucrat : "<< max << std::endl;
	Bureaucrat copy = max;
	std::cout << "Copy constructed from Maximal Bureaucrat : "<< copy << std::endl;
	Bureaucrat toBeAssigned;
	toBeAssigned = def;
	std::cout << "Copy assigned from default Bureaucrat : "<< toBeAssigned << std::endl;

	std::cout << std::endl << "Testing creation of bureaucrats with illegal grades"<< std::endl << std::endl;
	try {
		Bureaucrat overMax("Rupert", 0);
	}
	catch (const Bureaucrat::GradeTooHighException &e){
		std::cout << "Caught exception : "<< e.what() << std::endl;
	}
	try {
		Bureaucrat underMin("Rupert", 151);
	}
	catch (const Bureaucrat::GradeTooLowException &e){
		std::cout << "Caught exception : "<< e.what() << std::endl;
	}	

	std::cout << std::endl << "Testing increment/decrement of bureaucrats" << std::endl;
	try {		
		std::cout << std::endl << max << " After decrement(), becomes : ";
		max.decrementGrade();
		std::cout << max << std::endl;
		std::cout << "Trying to increment twice :" << std::endl;
		max.incrementGrade();	
		std::cout << max << std::endl;
		max.incrementGrade();	
	} catch (const Bureaucrat::GradeTooHighException &e){
		std::cout << "Caught exception : "<< e.what() << std::endl;
	}

	try {		
		std::cout << std::endl << def << " After increment(), becomes : ";
		def.incrementGrade();
		std::cout << def << std::endl;
		std::cout << "Trying to decrement twice :" << std::endl;
		def.decrementGrade();	
		std::cout << def << std::endl;
		def.decrementGrade();	
	} catch (const Bureaucrat::GradeTooLowException &e){
		std::cout << "Caught exception : "<< e.what() << std::endl;
	}
	

	return 0;
}
