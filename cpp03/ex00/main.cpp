#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap jason("Jason");
    ClapTrap someone;
    
    jason.attack("Bot");
    jason.attack("Bot");
    jason.takeDamage(100);
    jason.attack("Bot");
    jason.beRepaired(10);
    someone.attack("jack");
    someone.attack("jack");
}