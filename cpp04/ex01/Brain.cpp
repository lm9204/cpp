#include <iostream>
#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Constructor is called" << std::endl;
}

Brain::Brain(const Brain& ref)
{
	std::cout << "Brain Copy Constructor is called" << std::endl;
	*this = ref;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor is called" << std::endl;
}


Brain&	Brain::operator=(const Brain& ref)
{
	if (this == &ref)
		return *this;

	for (int i = 0; i < 100; ++i)
	{
		this->ideas[i] = ref.ideas[i];
	}
	std::cout << "Brain Assignment operator is called" << std::endl;
	return *this;
}

void	Brain::showIdeas() const
{
	std::cout << "[ Brain Ideas ]" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::cout << i << ": " <<  this->ideas[i] << std::endl;
	}
}

void	Brain::setBrain(std::string* newIdeas)
{
	for (int i = 0; i < 100; ++i)
	{
		this->ideas[i] = newIdeas[i];
	}
}