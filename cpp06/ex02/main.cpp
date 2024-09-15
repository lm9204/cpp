#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate();
void	identify(Base* p);
void	identify(Base& p);

int main()
{
	Base*	test1 = generate();
	Base*	test2 = generate();
	A	a;
	B	b;
	C	c;

	identify(test1);
	identify(test2);
	identify(a);
	identify(b);
	identify(c);

	return (0);
}

Base*	generate()
{
	Base* res;

	std::srand(std::clock());
	switch (std::rand() % 3)
	{
	case 0:
		res = new A();
		break;
	
	case 1:
		res = new B();
		break;

	case 2:
		res = new C();
		break;
	default:
		res = NULL;
		break;
	}
	return res;
}

void	identify(Base* p)
{
	A*	a;
	B*	b;
	C*	c;

	a = dynamic_cast<A *>(p);
	if (a)
		std::cout << "A\n";
	
	b = dynamic_cast<B *>(p);
	if (b)
		std::cout << "B\n";

	c = dynamic_cast<C *>(p);
	if (c)
		std::cout << "C\n";

}

void	identify(Base& p)
{
	A	a;
	B	b;
	C	c;

	try
	{
		a = dynamic_cast<A&>(p);
		std::cout << "A\n";
	}
	catch(const std::exception& e) {}

	try
	{
		b = dynamic_cast<B&>(p);
		std::cout << "B\n";
	}
	catch(const std::exception& e) {}

	try
	{
		c = dynamic_cast<C&>(p);
		std::cout << "C\n";
	}
	catch(const std::exception& e) {}	
}