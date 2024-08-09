#include <iostream>

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm Constructor is called" << "\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref)
{
	std::cout << "RobotomyRequestForm Copy Constructor is called" << "\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor is called" << "\n";

}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& ref)
{
	std::cout << "RobotomyRequestForm Assignment Operator is called" << "\n";
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getRequiredExecGrade() < executor.getGrade())
		throw GradeTooLowException();
	if (!this->getIsSigned())
		throw FormNotSignedException();

	std::cout << "Bzzzz Bzzzz Bzzzz..." << "\n";
	std::srand(std::time(0));
	if (std::rand() % 2 == 0)
		std::cout << this->_target << " successfully robotomized" << "\n";
	else
		std::cout << this->_target << " robomize failed" << "\n";
}