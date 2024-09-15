#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat a("David", 2);
	Intern	yeondcho;

	AForm* forms[3];

	try
	{
		forms[0] = yeondcho.makeform("shrubbery creation", "a");
		forms[1] = yeondcho.makeform("robotomy request", "David");
		forms[2] = yeondcho.makeform("presidential pardon", "Someone");

		AForm* errorForm = yeondcho.makeform("weird things", "yeondcho");
		if (errorForm != NULL)
			std::cout << *errorForm << "\n";

		std::cout << *forms[0] << "\n";
		std::cout << *forms[1] << "\n";
		std::cout << *forms[2] << "\n";

		a.signForm(*forms[0]);
		a.executeForm(*forms[0]);
		a.signForm(*forms[1]);
		a.executeForm(*forms[1]);
		a.signForm(*forms[2]);
		a.executeForm(*forms[2]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	for (int i = 0; i < 3; ++i)
		if (forms[i] != NULL)
			delete forms[i];
	return (0);
}