#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& ref);
	~RobotomyRequestForm();
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& ref);

	void	beSigned(const Bureaucrat& Bureaucrat);
};

#endif