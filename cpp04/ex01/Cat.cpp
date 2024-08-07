#include <iostream>
#include "Cat.hpp"

Cat::Cat()
{ 
    this->_type = "Cat";
    this->_brain = new Brain(); 
    std::cout << "Cat Constructor is called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor is called" << std::endl;
    delete this->_brain;
}

Cat::Cat(const Cat& ref) : Animal(ref)
{
    *this = ref;
    std::cout << "Cat Copy Constructor is called" << std::endl;
}

Cat&    Cat::operator=(const Cat& ref)
{
    if (this == &ref)
        return *this;

    this->_type = ref._type;
    std::cout << "Cat Assignment operator is called" << std::endl;
    return *this;
}

void    Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}
