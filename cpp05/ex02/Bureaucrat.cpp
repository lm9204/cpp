#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat Constructor is called" << "\n";
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref)
{
	std::cout << "Bureaucrat Copy Constructor is called" << "\n";
	*this = ref;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor is called" << "\n";
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& ref)
{
	std::cout << "Bureaucrat Assignment Operator is called" << "\n";
	if (this == &ref)
		return *this;

	this->_name = ref._name;
	this->_grade = ref._grade;
	return *this;
}

const std::string	Bureaucrat::getName() const
{
	return this->_name;
}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

void	Bureaucrat::increment()
{
	if (this->_grade <= 1)
		throw GradeTooHighException();

	this->_grade--;
}

void	Bureaucrat::decrement()
{
	if (this->_grade >= 150)
		throw GradeTooLowException();

	this->_grade++;
}

void	Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << this->_name << " couldn’t sign "
		<< form.getName() << " because " << e.what() << ".\n";
	}
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& ref)
{
	os << ref.getName() << ", bureaucrat grade " << ref.getGrade() << ".";
	return os;
}

char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return const_cast<char*>("Grade Too High");
}

char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return const_cast<char*>("Grade Too Low");
}