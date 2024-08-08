#include "Form.hpp"

Form::Form(std::string name, int signGrade, int executeGrade) : _name(name) , _requiredSign(signGrade), _requiredExecute(executeGrade), _isSigned(false)
{
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	std::cout << "Form Constructor is called" << "\n";
}

Form::Form(const Form& ref) : _name(ref.getName()) , _requiredSign(ref.getRequiredSignGrade()), _requiredExecute(ref.getRequiredExecGrade()), _isSigned(false)
{
	*this = ref;
	std::cout << "Form Copy Constructor is called" << "\n";
}

Form::~Form()
{
	std::cout << "Form Destructor is called" << "\n";
}

Form&	Form::operator=(const Form& ref)
{
	if (this == &ref)
		return *this;

	this->_isSigned = ref._isSigned;
	std::cout << "Form Assignment Operator is called" << "\n";
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->_requiredSign < bureaucrat.getGrade())
		throw GradeTooLowException();
	
	this->_isSigned = true;
}

const std::string	Form::getName() const
{
	return _name;
}

int	Form::getRequiredExecGrade() const
{
	return _requiredExecute;
}

int	Form::getRequiredSignGrade() const
{
	return	_requiredSign;
}

bool	Form::getIsSigned() const
{
	return _isSigned;
}

char*	Form::GradeTooHighException::what() const throw()
{
	return const_cast<char*>("Grade Too High");
}

char*	Form::GradeTooLowException::what() const throw()
{
	return const_cast<char*>("Grade Too Low");
}


std::ostream& operator<<(std::ostream& os, const Form& ref)
{
	os << ref.getName() << " Form, require Sign Grade " << ref.getRequiredSignGrade() << ", require Execute Grade " << ref.getRequiredExecGrade() << ", Signed " << ref.getIsSigned();
}
