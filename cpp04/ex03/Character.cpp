#include <iostream>
#include <Character.hpp>

Character::Character() : _name("someone"), _idx(0)
{
	for (int i=0; i<4; ++i)
		_inventory[i] = NULL;
}

Character::Character(std::string name) : _name(name), _idx(0)
{
	for (int i=0; i<4; ++i)
		_inventory[i] = NULL;
}

Character::Character(const Character& ref)
{
	this->_name = ref._name;
	for (int i=0; i<4;++i)
		this->_inventory[i] = ref._inventory[i];
}

Character::~Character()
{

}

Character&	Character::operator=(const Character& ref)
{
	if (this == &ref)
		return *this;

	this->_name = ref._name;
	for (int i=0; i<4;++i)
		this->_inventory[i] = ref._inventory[i];
	return *this;
}

std::string const &	Character::getName() const
{
	return this->_name;
}

void	Character::equip(AMateria* m)
{
	if (_idx < 4 && _inventory[_idx] != NULL)
		return;
	_inventory[_idx++] = m;
}

void	Character::unequip(int idx)
{
	if (_inventory[idx] == NULL)
		return;
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (this->_inventory[idx] == NULL)
		return;
	this->_inventory[idx]->use(target);
}