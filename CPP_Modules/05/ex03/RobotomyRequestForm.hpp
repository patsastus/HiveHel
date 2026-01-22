#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <random>
#include <iostream>

class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm();
	RobotomyRequestForm(std::string const &target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();

protected:
	virtual void beExecuted()  const override; 

private:
	std::string target_;
};

#endif // ROBOTOMYREQUESTFORM_HPP
