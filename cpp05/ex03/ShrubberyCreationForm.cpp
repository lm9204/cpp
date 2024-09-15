#include <iostream>
#include <fstream>
#include <string>

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137), _target(target)
{
	std::cout << "Shrubbery Form Constructor is called" << "\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref) : AForm(ref._target, 145, 137)
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
	
	std::cout << "Shrubbery Form Assignment Operator is called" << "\n";
	this->_target = ref._target;
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
		outfile << "              v .   ._, |_  .," << "\n"
				<< "           `-._\\/  .  \\ /    |/_" << "\n"
				<< "               \\\\  _\\, y | \\//" << "\n"
				<< "         _\\_.___\\\\, \\/ -.\\||" << "\n"
				<< "           `7-,--.`._||  / / ," << "\n"
				<< "           /'     `-. `./ / |/_.'" << "\n"
				<< "                     |    |//" << "\n"
				<< "                     |_    /" << "\n"
				<< "                     |-   |" << "\n"
				<< "                     |   =|" << "\n"
				<< "                     |    |" << "\n"
				<< "--------------------/ ,  . \\--------._" << "\n";
	}
	else
		std::cout << "Failed to creating file" << "\n";
}