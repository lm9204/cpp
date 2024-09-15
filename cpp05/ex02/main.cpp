#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat a("David", 2);
	Bureaucrat b("Jackson", 60);
	PresidentialPardonForm pform("pform");
	PresidentialPardonForm pnotform("pnotform");
	RobotomyRequestForm rform("rform");
	RobotomyRequestForm rnotform("rnotform");
	ShrubberyCreationForm sform("sform");
	ShrubberyCreationForm snotform("snotform");
	
	std::cout << a << "\n";
	std::cout << b << "\n";

	try
	{
		a.signForm(pform);
		a.executeForm(pform);
		
		a.signForm(rform);
		a.executeForm(rform);
		
		a.signForm(sform);
		a.executeForm(sform);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}

	try
	{
		b.signForm(pnotform);
		b.executeForm(pnotform);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}

	try
	{
		b.signForm(rnotform);
		b.executeForm(rnotform);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}

	try
	{
		b.signForm(snotform);
		b.executeForm(snotform);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}

	return (0);
}