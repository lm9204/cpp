#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <string>
# include "AForm.hpp"
# include "Bureaucrat.hpp"


class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& ref);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& ref);

		void	execute(Bureaucrat const & executor) const;

	private:
		std::string	_target;
		
		ShrubberyCreationForm();
};

#endif