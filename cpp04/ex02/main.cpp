#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    Animal* animals[50];

    for (int i = 0; i < 50; ++i)
    {
        if (i % 2 == 0)
            animals[i] = new Cat();
        else
            animals[i] = new Dog();
    }

    for (int i = 0; i < 50; ++i)
        animals[i]->makeSound();

    for (int i = 0; i < 50; ++i)
        delete animals[i];

    return 0;
}
