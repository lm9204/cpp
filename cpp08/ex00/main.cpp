#include <iostream>
#include <vector>

#include "easyfind.hpp"

int main()
{
	std::vector<int> a;

	for (int i = 0; i < 10; ++i)
		a.push_back(i * i);
	
	try
	{
		std::cout << easyfind(a, 81) << "\n";
		std::cout << easyfind(a, 100) << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}