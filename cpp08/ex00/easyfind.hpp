#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iterator>
# include <algorithm>
# include <exception>

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	
	// 값을 찾지 못한 경우 예외 던지기
	if (it == container.end()) {
		throw std::out_of_range("couldn't find value");
	}
	return it; // 값을 찾은 경우 반복자 반환
}

#endif