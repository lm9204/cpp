#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_hit = this->_base_hit;
	this->_energy = this->_base_energy;
	this->_damage = this->_base_damage;
	std::cout << "FragTrap Constructor is called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hit = this->_base_hit;
	this->_energy = this->_base_energy;
	this->_damage = this->_base_damage;
	std::cout << "FragTrap Constructor is called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& ref) : ClapTrap(ref)
{
	this->_name = ref._name;
	this->_hit = ref._hit;
	this->_energy = ref._energy;
	this->_damage = ref._damage;
	std::cout << "FragTrap Constructor is called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor is called" << std::endl;
}


FragTrap&    FragTrap::operator=(const FragTrap& ref)
{
	if (this == &ref)
		return *this;
	
	this->_name = ref._name;
	this->_hit = ref._hit;
	this->_energy = ref._energy;
	this->_damage = ref._damage;
	std::cout << "FragTrap Assignment operator is called" << std::endl;
	return *this;
}

void    FragTrap::highFivesGuys(void) const
{
	std::cout << this->_name << " wants HighFive!!" << std::endl;
}