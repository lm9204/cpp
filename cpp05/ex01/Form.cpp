#include "Form.hpp"

Form::Form()
{

}

Form::Form(const Form& ref)
{

}

Form::~Form()
{

}

Form&	Form::operator=(const Form& ref)
{

}

void	Form::beSigned(const Bureaucant& bureaucant)
{
	
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
	os << ref._name << " Form, require Sign Grade " << ref._requiredSign << ", require Execute Grade " << ref._requiredExecute << ", Signed " << ref._isSigned;
}
