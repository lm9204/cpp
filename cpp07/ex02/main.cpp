#include "Array.hpp"

int main()
{
	Array<int> a(10);
	int* n = new int(10);
	
	for (int i = 0; i < 10; ++i)
	{
		a[i] = i;
		n[i] = i;
	}

	for (int i = 0; i < 10; ++i)
		std::cout << "a: " << a[i] << ", n: " << n[i] << "\n";

	std::cout << "[Wrong Index Apporach]\n";
	try
	{
		a[10] = 1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n";

	std::cout << "[Copy Constructor && Assignment Operator]\n";
	Array<int> b = a;
	Array<int> c(a);

	for (size_t i = 0; i < b.size(); ++i)
		std::cout << "b: " << b[i] << ", c: " << c[i] << "\n";
	
	delete n;
	return (0);
}