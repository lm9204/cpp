#include "Zombie.hpp"
#include <stdlib.h>


Zombie* zombieHorde(int N, std::string name);

void    f(void)
{
    system("leaks horde");
}

int main(void)
{
    atexit(f);
    Zombie* horde = zombieHorde(10, "zzzzzombieeeeeeeee");
    for (int i = 0; i < 10; ++i)
        horde[i].announce();
    delete[] horde;
}