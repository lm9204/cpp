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
	
		class FormNotSignedException : public std::exception
		{
			public:
				char*	what() const throw();
		};

		AForm();
		AForm(std::string name, int signGrade, int executeGrade);
		AForm(const AForm& ref);
		virtual ~AForm();
		AForm&	operator=(const AForm& ref);

		void	beSigned(const Bureaucrat& bureaucrat);
		virtual void	execute(Bureaucrat const & executor) const = 0;
		const std::string getName() const;
		int 	getRequiredSignGrade() const;
		int 	getRequiredExecGrade() const;
		bool	getIsSigned() const;
		void	setSign(bool flag);

	private:
		const std::string _name;
		const int	_requiredSign;
		const int	_requiredExecute;
		bool	_isSigned;

};

std::ostream& operator<<(std::ostream& os, const AForm& ref);

#endif