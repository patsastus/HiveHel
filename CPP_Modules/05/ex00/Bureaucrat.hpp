#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <exception>
#include <string>
#include <iostream>

class Bureaucrat {
public:
    Bureaucrat();
	Bureaucrat(std::string const &name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

	//struct and class are 99.9% equivalent
	struct GradeTooHighException : public std::exception {
		const char* what() const noexcept override;
	};
	class GradeTooLowException : public std::exception {
		public:
		const char* what() const noexcept override;
	};
	std::string const &getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();

private:
	int 				grade_;
	std::string const	name_;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif // BUREAUCRAT_HPP
