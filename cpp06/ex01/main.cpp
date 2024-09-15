#include <iostream>
#include <cstdint>

#include "Serializer.hpp"

int main()
{
	Data *a = new Data("yeondcho");
	uintptr_t serialized = Serializer::serialize(a);
	Data *b = Serializer::deserialize(serialized);

	std::cout << a << " " << a->getName() << "\n";
	std::cout << serialized << "\n";
	std::cout << b << " " << b->getName() << "\n";

	return (0);
}