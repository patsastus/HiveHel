#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

class PresidentialPardonForm : public AForm {
public:
    PresidentialPardonForm();
	PresidentialPardonForm(std::string const &target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();
	virtual void execute(Bureaucrat const & executor) const;

private:
	std::string target_;
};

#endif // PRESIDENTIALPARDONFORM_HPP
