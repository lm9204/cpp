#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardon", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm Constructor is called" << "\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref) : AForm(ref._target, 25, 5)
{
	std::cout << "PresidentialPardonForm Copy Constructor is called" << "\n";
	*this = ref;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor is called" << "\n";
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& ref)
{
	if (this == &ref)
		return *this;
	std::cout << "PresidentialPardonForm Assignment Operator is called" << "\n";
	this->_target = ref._target;
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getRequiredExecGrade() < executor.getGrade())
		throw GradeTooLowException();
	if (!this->getIsSigned())
		throw FormNotSignedException();

	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << "\n";
}