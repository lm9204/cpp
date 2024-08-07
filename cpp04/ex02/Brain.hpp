#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>

class Brain
{
	public:
		Brain();
		~Brain();
		Brain(const Brain& ref);
		Brain&	operator=(const Brain& ref);
		
		std::string	ideas[100];
};

#endif