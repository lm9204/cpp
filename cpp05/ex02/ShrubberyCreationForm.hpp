#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& ref);
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& ref);

	void	beSigned(const Bureaucrat& bureaucrat);
};

#endif