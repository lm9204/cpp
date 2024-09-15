#include <iostream>

#include "iter.hpp"

template <typename T>
void	print(T& value)
{
	std::cout << value << " ";
}
	
int main()
{
	std::string s1[5] = {"a", "b", "c", "d", "e"};
	const std::string s2[2] = {"abcde", "fghijk"};
	int n1[5] = {0, 1, 2, 3, 4};
	const int n2[5] = {9, 8, 7, 6, 5};
	char s3[] = "hello world";

	iter(s1, 5, print);
	std::cout << "\n";
	iter(s2, 2, print);
	std::cout << "\n";
	iter(n1, 5, print);
	std::cout << "\n";
	iter(n2, 5, print);
	std::cout << "\n";
	iter(s3, 12, print);
	std::cout << "\n";


	return (0);
}