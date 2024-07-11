#include "HumanB.hpp"

HumanB::HumanB() : _name(""), _weapon("") {}

HumanB::HumanB(std::string name) : _name(name) {}

HumanB::~HumanB() {}

void    HumanB::setWeapon(Weapon& type)
{
    this->_weapon = type;
}

void    HumanB::attack() const
{
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}