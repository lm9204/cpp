#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap diamond("Dia");

    diamond.guardGate();
    diamond.attack("someone");
    diamond.whoAmI();
    diamond.highFivesGuys();
}