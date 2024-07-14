#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap jason("Jason");
    ClapTrap someone;
    
    jason.attack("Bot");
    jason.setDamage(2);
    jason.attack("Bot");
    jason.attack("Bot");
    jason.attack("Bot");
    jason.attack("Bot");
    jason.attack("Bot");
    jason.attack("Bot");
    jason.attack("Bot");
    jason.attack("Bot");
    jason.takeDamage(10);
    jason.beRepaired(10);
    someone.setDamage(10);
    someone.attack("jack");
    someone.attack("jack");
    someone.attack("jack");
    someone.attack("jack");
    someone.attack("jack");
    someone.attack("jack");
    someone.attack("jack");
    someone.attack("jack");
    someone.attack("jack");
    someone.attack("jack");
    someone.attack("jack");
    someone.attack("jack");
    someone.attack("jack");
    someone.attack("jack");
    someone.attack("jack");
}