#include "HumanA.hpp"

HumanA::HumanA() : _name(""), _weapon("") {}

HumanA::HumanA(std::string name, Weapon& type) : _name(name), _weapon(type) {}

HumanA::~HumanA() {}

void    HumanA::attack() const
{
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
