#include <iostream>

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() : _form_types("shrubbery creation,robotomy request,presidential pardon")
{
	std::cout << "Intern Constructor is called\n";
}

Intern::Intern(const Intern& ref)
{
	*this = ref;
	std::cout << "Intern Copy Constructor is called\n";
}

Intern::~Intern()
{
	std::cout << "Intern Destructor is called\n";
}

Intern&	Intern::operator=(const Intern& ref)
{
	if (this == &ref)
		return *this;

	std::cout << "Intern Assignment Operator is called\n";
	this->_form_types = ref._form_types;
	return *this;
}

AForm*	Intern::makeform(std::string name, std::string target)
{
	AForm*	returnForm = NULL;

	if (static_cast<int>(name.find(',')) >= 0 || name.length() > 20)
	{
		std::cerr << "Wrong type Form.\n";
		return (NULL);
	}

	switch (_form_types.find(name))
	{
		case 0:
			returnForm = new ShrubberyCreationForm(target);
			std::cout << "Intern creates ShrubberyCreationForm.\n";
			break;
		case 19:
			returnForm = new RobotomyRequestForm(target);
			std::cout << "Intern creates RobotomyRequestForm.\n";
			break;
		case 36:
			returnForm = new PresidentialPardonForm(target);
			std::cout << "Intern creates PresidentialPardonForm.\n";
			break;
		default:
			std::cerr << "Wrong type Form.\n";
			break;
	}

	return returnForm;
}