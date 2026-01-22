#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <exception>
#include <string>
#include <filesystem>

class ShrubberyCreationForm : public AForm {
public:
    ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const &target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();
	virtual void execute(Bureaucrat const & executor) const;

private:
	std::string target_;
};

#endif // SHRUBBERYCREATIONFORM_HPP
