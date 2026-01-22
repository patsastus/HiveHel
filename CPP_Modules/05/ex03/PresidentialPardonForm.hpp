#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class PresidentialPardonForm : public AForm {
public:
    PresidentialPardonForm();
	PresidentialPardonForm(std::string const &target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();

protected:
	virtual void beExecuted()  const override; 

private:
	std::string target_;
};

#endif // PRESIDENTIALPARDONFORM_HPP
