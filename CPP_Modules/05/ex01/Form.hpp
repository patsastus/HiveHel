#ifndef FORM_HPP
#define FORM_HPP
#include <exception>
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

//forward declaration
class Bureaucrat;

class Form {
public:
    Form();
	Form(std::string const &name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

	struct GradeTooHighException : public std::exception {
		const char* what() const noexcept override;
	};
	struct GradeTooLowException : public std::exception {
		const char* what() const noexcept override;
	};

	void beSigned(Bureaucrat const& b);
	std::string const &getName() const;
	bool isSigned() const;

private:
	std::string const	name_;
	bool				isSigned_;
	int const			gradeToSign_;
	int const			gradeToExecute_;
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif // FORM_HPP
