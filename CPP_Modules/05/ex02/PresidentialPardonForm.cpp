#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("PresidentialPardonForm", 25, 5)
	, target_("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) 
	: AForm("PresidentialPardonForm", 25, 5)
	, target_(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
	: AForm(other)
	, target_(other.target_)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
      this->target_ = other.target_;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() { 
}
