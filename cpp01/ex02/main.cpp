#include <iostream>
#include <string>

int main(void)
{
    std::string     a = "HI THIS IS BRAIN";
    std::string*    stringPTR = &a;
    std::string&    stringREF = a;

    std::cout << "=========== Address ===========" << std::endl;
    std::cout << "origin string address " << &a << std::endl;
    std::cout << "pointer string address " << &stringPTR << std::endl;
    std::cout << "reference string address " << &stringREF << std::endl;
    std::cout << "=========== Value ===========" << std::endl;
    std::cout << "origin string " << a << std::endl;
    std::cout << "pointer string " << *stringPTR << std::endl;
    std::cout << "reference string " << stringREF << std::endl;
}