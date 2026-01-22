#ifndef AFORM_HPP
#define AFORM_HPP
#include <exception>
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

//forward declaration
class Bureaucrat;

class AForm {
public:
    AForm();
	AForm(std::string const &name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

	struct GradeTooHighException : public std::exception {
		const char* what() const noexcept override;
	};
	struct GradeTooLowException : public std::exception {
		const char* what() const noexcept override;
	};

	void beSigned(Bureaucrat const& b);
	std::string const &getName() const;
	bool isSigned() const;
	virtual void execute(Bureaucrat const & executor) const = 0;

private:
	std::string const	name_;
	bool				isSigned_;
	int const			gradeToSign_;
	int const			gradeToExecute_;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif // AFORM_HPP
