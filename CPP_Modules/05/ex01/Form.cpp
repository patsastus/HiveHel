#include "Form.hpp"

Form::Form() 
	: name_("Default")
	, isSigned_(false)
	, gradeToSign_(1)
	, gradeToExecute_(1)
{
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute)
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

Form::Form(const Form& other) 
	: name_(other.name_)
	, isSigned_(other.isSigned_)
	, gradeToSign_(other.gradeToSign_)
	, gradeToExecute_(other.gradeToExecute_)
{
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
    }
    return *this;
}

Form::~Form() {
}

void Form::beSigned(Bureaucrat const& b){
	if (b.getGrade() > gradeToSign_)
		throw Form::GradeTooLowException();
	isSigned_ = true;
}

std::string const &Form::getName() const{
	return name_;
}

bool Form::isSigned() const{
	return isSigned_;
}


const char* Form::GradeTooHighException::what() const noexcept{
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const noexcept{
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form '" << f.getName() << "' ";
	if ( f.isSigned() ) 
		os << "(signed)";
	else
		os << "(unsigned)";
    return os;
}
