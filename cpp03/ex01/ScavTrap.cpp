#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->_name = "ScavTrap";
    this->_hit = this->_base_hit;
    this->_energy = this->_base_energy;
    this->_damage = this->_base_damage;
    std::cout << "ScavTrap Constructor is called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hit = this->_base_hit;
    this->_energy = this->_base_energy;
    this->_damage = this->_base_damage;
    std::cout << "ScavTrap Constructor is called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& ref) : ClapTrap(ref)
{
    *this = ref;
    std::cout << "ScavTrap Copy Constructor is called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor is called" << std::endl;
}

ScavTrap&   ScavTrap::operator=(const ScavTrap& ref)
{
    if (this == &ref)
        return *this;
    this->_name = ref._name;
    this->_hit = ref._hit;
    this->_energy = ref._energy;
    this->_damage = ref._damage;
    std::cout << "ScavTrap Assignment Operator is called" << std::endl;
    return (*this);
}

void    ScavTrap::guardGate() const
{
    std::cout << "ScavTrap " << this->_name << " is now on GateKeeper mode!" << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if (this->_hit == 0 && this->_energy != 0)
    {
        std::cout << "ScavTrap "<< this->_name << " seems not working anymore :(" << std::endl;
        return;
    }
    if (this->_energy == 0)
    {
        std::cout << "ScavTrap " << this->_name << " hasn't enough Energy!!!" << std::endl;
        return;
    }

    std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_damage << " points of damage!" << std::endl;
    this->_energy--;
}