#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardon", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm Constructor is called" << "\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref)
{
	std::cout << "PresidentialPardonForm Copy Constructor is called" << "\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor is called" << "\n";
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& ref)
{
	std::cout << "PresidentialPardonForm Assignment Operator is called" << "\n";
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getRequiredExecGrade() < executor.getGrade())
		throw GradeTooLowException();
	if (!this->getIsSigned())
		throw FormNotSignedException();

	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << "\n";
}