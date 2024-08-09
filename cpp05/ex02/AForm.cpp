#include "AForm.hpp"

AForm::AForm(std::string name, int signGrade, int executeGrade) : _name(name) , _requiredSign(signGrade), _requiredExecute(executeGrade), _isSigned(false)
{
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	std::cout << "AForm Constructor is called" << "\n";
}

AForm::AForm(const AForm& ref) : _name(ref.getName()) , _requiredSign(ref.getRequiredSignGrade()), _requiredExecute(ref.getRequiredExecGrade()), _isSigned(false)
{
	*this = ref;
	std::cout << "AForm Copy Constructor is called" << "\n";
}

AForm::~AForm()
{
	std::cout << "AForm Destructor is called" << "\n";
}

AForm&	AForm::operator=(const AForm& ref)
{
	if (this == &ref)
		return *this;

	this->_isSigned = ref._isSigned;
	std::cout << "AForm Assignment Operator is called" << "\n";
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->_requiredSign < bureaucrat.getGrade())
		throw GradeTooLowException();
	
	this->_isSigned = true;
}

const std::string	AForm::getName() const
{
	return _name;
}

int	AForm::getRequiredExecGrade() const
{
	return _requiredExecute;
}

int	AForm::getRequiredSignGrade() const
{
	return	_requiredSign;
}

bool	AForm::getIsSigned() const
{
	return _isSigned;
}

void	AForm::setSign(bool flag)
{
	this->_isSigned = flag;
}

char*	AForm::GradeTooHighException::what() const throw()
{
	return const_cast<char*>("GRADE IS TOO HIGH");
}

char*	AForm::GradeTooLowException::what() const throw()
{
	return const_cast<char*>("GRADE IS TOO LOW");
}

char*	AForm::FormNotSignedException::what() const throw()
{
	return const_cast<char*>("FORM IS NOT SIGNED");
}


std::ostream& operator<<(std::ostream& os, const AForm& ref)
{
	os << ref.getName() << " AForm, require Sign Grade " << ref.getRequiredSignGrade() << ", require Execute Grade " << ref.getRequiredExecGrade() << ", Signed " << ref.getIsSigned();
}
