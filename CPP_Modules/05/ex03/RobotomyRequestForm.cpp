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

void RobotomyRequestForm::beExecuted() const {
	std::cout << "**Drilling noises**" << std::endl;
	std::random_device rd; //adapted from en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution.html
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 1);
	if ( dis(gen) == 1 ){
		std::cout << target_ << " has been successfully robotomized" << std::endl;
	} else {
		std::cout << "Robotomy on " << target_ << " failed" << std::endl;
	}
}
