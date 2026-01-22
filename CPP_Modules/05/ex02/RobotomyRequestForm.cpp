#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("RobotomyRequestForm", 72, 45)
	, target_("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) 
	: AForm("RobotomyRequestForm", 72, 45)
	, target_(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
	: AForm(other)
	, target_(other.target_)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
      this->target_ = other.target_;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() { 
}
