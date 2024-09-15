#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>

template <typename T>
int	easyfind(T& arr, int n)
{
	for (size_t i = 0; i < arr.size(); ++i)
	{
		if (arr[i] == n)
			return n;
	}

	throw std::invalid_argument("Nothing found");
}

#endif