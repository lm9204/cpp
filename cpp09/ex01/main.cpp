#include <iostream>

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);

	try
	{
		RPN program(argv[1]);
		program.run();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}