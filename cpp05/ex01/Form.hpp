#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucant;

class Form
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

		Form();
		Form(const Form& ref);
		~Form();
		Form&	operator=(const Form& ref);

		void	beSigned(const Bureaucant& bureaucant);
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

std::ostream& operator<<(std::ostream& os, const Form& ref);

#endif