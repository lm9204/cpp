#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"


int main()
{
    Cat*    cat1 = new Cat();
    Cat*    cat2 = new Cat();
    Dog*    dog1 = new Dog();
    Dog*    dog2 = new Dog();
    Brain*  brain = new Brain();
    std::string* ideas = new std::string[100];

    ideas[0] = "cat";
    ideas[1] = "meow";
    ideas[2] = "catnip";
    ideas[3] = "meow";
    ideas[4] = "ha...";
    brain->setBrain(ideas);
    cat1->setBrain(*brain);
    cat1->getBrain().showIdeas();

    delete cat1;
    delete cat2;
    delete dog1;
    delete dog2;
    delete brain;
    delete[] ideas;


    return 0;
}
