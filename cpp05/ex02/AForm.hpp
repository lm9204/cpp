#ifndef AFORM_HPP
# define AFORM_HPP
# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
			class GradeTooHighException : public std::exception
			{
				public:
					char*	what() const throw();
			};

			class GradeTooLowException : public std::exception
			{
				public:
					char*	what() const throw();
			};

		AForm();
		AForm(std::string name, int signGrade, int executeGrade);
		AForm(const AForm& ref);
		virtual ~AForm();
		AForm&	operator=(const AForm& ref);

		virtual void	beSigned(const Bureaucrat& bureaucrat);
		const std::string getName() const;
		int 	getRequiredSignGrade() const;
		int 	getRequiredExecGrade() const;
		bool	getIsSigned() const;

	private:
		const std::string _name;
		const int	_requiredSign;
		const int	_requiredExecute;
		bool	_isSigned;

};

std::ostream& operator<<(std::ostream& os, const AForm& ref);

#endif