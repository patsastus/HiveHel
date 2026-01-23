#include "AForm.hpp"

AForm::AForm() 
	: name_("Default")
	, isSigned_(false)
	, gradeToSign_(1)
	, gradeToExecute_(1)
{
}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute)
	: name_(name)
	, isSigned_(false)
	, gradeToSign_(gradeToSign)
	, gradeToExecute_(gradeToExecute) 
{
	if (gradeToSign_ < 1 || gradeToExecute_ < 1)
		throw GradeTooHighException();
	if (gradeToSign_ > 150 || gradeToExecute_ > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other) 
	: name_(other.name_)
	, isSigned_(other.isSigned_)
	, gradeToSign_(other.gradeToSign_)
	, gradeToExecute_(other.gradeToExecute_)
{
}

AForm& AForm::operator=(const AForm& other) {
	(void)other;
    return *this;
}

AForm::~AForm() {
}

void AForm::beSigned(Bureaucrat const& b){
	if (b.getGrade() > gradeToSign_)
		throw AForm::GradeTooLowException();
	isSigned_ = true;
}

std::string const &AForm::getName() const{
	return name_;
}

bool AForm::isSigned() const{
	return isSigned_;
}

void AForm::execute(Bureaucrat const & executor) const{
	if (!isSigned_)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > gradeToExecute_) 
		throw AForm::GradeTooLowException();
	beExecuted();
}

const char* AForm::GradeTooHighException::what() const noexcept{
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const noexcept{
	return "Grade too low";
}

const char* AForm::FormNotSignedException::what() const noexcept{
	return "Form not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "AForm '" << f.getName() << "' ";
	if ( f.isSigned() ) 
		os << "(signed)";
	else
		os << "(unsigned)";
    return os;
}
