#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <string>
#include <iostream>

class ShrubberyCreationForm : public AForm {
public:
    ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const &target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();

protected:
	virtual void beExecuted()  const override; 

private:
	std::string target_;
};

#endif // SHRUBBERYCREATIONFORM_HPP
