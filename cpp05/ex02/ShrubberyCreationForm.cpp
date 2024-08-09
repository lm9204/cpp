#include <iostream>
#include <fstream>
#include <string>

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137), _target(target)
{
	std::cout << "Shrubbery Form Constructor is called" << "\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref)
{
	std::cout << "Shrubbery Form Copy Constructor is called" << "\n";
	*this = ref;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Form Desturctor is called" << "\n";
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref)
{
	if (this == &ref)
		return *this;
	
	this->_target = ref._target;
	std::cout << "Shrubbery Form Assignment Operator is called" << "\n";
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getRequiredExecGrade() < executor.getGrade())
		throw GradeTooLowException();
	if (!this->getIsSigned())
		throw FormNotSignedException();

	std::ofstream	outfile(this->_target + "_shrubbery", std::ios_base::out);
	if (outfile.is_open())
	{
		//ascii tree
	}
	else
		std::cout << "Failed to creating file" << "\n";
}