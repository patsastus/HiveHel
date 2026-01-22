#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() 
	: grade_(150)
	, name_("Anonymous")
{
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) 
	: name_(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw  GradeTooLowException();
	grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) 
	: grade_(other.grade_)
	, name_(other.name_)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->grade_ = other.grade_;
		//name_ is marked const, so no changing it after creation
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
}

std::string const & Bureaucrat::getName() const{
	return name_;
}

int Bureaucrat::getGrade() const{
	return grade_;
}

void Bureaucrat::incrementGrade(){
	if (grade_ > 1)
		--grade_;
	else
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade(){
	if (grade_ < 150)
		++grade_;
	else
		throw GradeTooLowException();
}

void Bureaucrat::signForm(Form &f){
	try {
		f.beSigned(*this);
		std::cout << *this << " signed " << f << std::endl;
	}
	catch (const Form::GradeTooLowException &e){
		std::cout << *this << " couldn't sign " << f << " because " << e.what() << std::endl;
	}
}


const char* Bureaucrat::GradeTooHighException::what() const noexcept{
	return "Grade too high, maximum value is 1";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept{
	return "Grade too low, minimum value is 150";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
