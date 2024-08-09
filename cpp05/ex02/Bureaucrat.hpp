#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <string>
# include "AForm.hpp"

class Bureaucrat
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

		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& ref);
		~Bureaucrat();
		Bureaucrat&	operator=(const Bureaucrat& ref);

		void	signForm(AForm& form) const;
		const std::string	getName() const;
		int					getGrade() const;
		void				increment();
		void				decrement();


	private:
		Bureaucrat();
		std::string	_name;
		int			_grade;

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& ref);

#endif