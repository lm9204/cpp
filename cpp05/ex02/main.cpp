#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("David", 2);

	try
	{
		a.getGrade();
		a.increment();
		a.getGrade();
		a.increment();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << a << "\n";

	return (0);
}