#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm();
	RobotomyRequestForm(std::string const &target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();
	virtual void execute(Bureaucrat const & executor) const;

private:
	std::string target_;
};

#endif // SHRUBBERYCREATIONFORM_HPP
