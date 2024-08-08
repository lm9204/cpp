#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& ref);
	~PresidentialPardonForm();
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& ref);

	void	beSigned(const Bureaucrat& Bureaucrat);
};

#endif