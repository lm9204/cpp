#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include "Data.hpp"
# include <cstdint>

class Serializer
{
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*	deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(const Serializer& ref);
		Serializer& operator=(const Serializer& ref);
		~Serializer();
};

#endif