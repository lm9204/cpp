#ifndef INTERN_HPP
# define INTERN_HPP
# include <string>

# include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& ref);
		~Intern();
		Intern&	operator=(const Intern& ref);

		AForm*	makeform(std::string name, std::string target);

	private:
		std::string	_form_types;

};

#endif