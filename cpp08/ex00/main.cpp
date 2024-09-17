#include <iostream>
#include <vector>
#include <list>

#include "easyfind.hpp"

int main()
{
	// 테스트를 위한 벡터 생성
	std::vector<int> vec;
	for (int i = 1; i <= 5; ++i)
		vec.push_back(i);

	std::cout << "[Vector] : ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << "\n";
	try {
		// 값을 찾는 예제
		std::vector<int>::iterator result = easyfind(vec, 3);
		std::cout << "Value found: " << *result << std::endl;
	} catch (const std::exception& e) {
		// 예외 처리
		std::cout << e.what() << std::endl;
	}

	try {
		// 없는 값을 찾는 예제
		std::vector<int>::iterator result = easyfind(vec, 6);
		std::cout << "Value found: " << *result << std::endl;
	} catch (const std::exception& e) {
		// 예외 처리
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n\n";

	std::list<int> list;
	for (int i = 1; i <= 1000; i += i)
		list.push_back(i);

	std::cout << "[List] : ";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";
	try {
		// 값을 찾는 예제
		std::list<int>::iterator result1 = easyfind(list, 2);
		std::cout << "Value found: " << *result1 << std::endl;

		std::list<int>::iterator result2 = easyfind(list, 32);
		std::cout << "Value found: " << *result2 << std::endl;

		std::list<int>::iterator result3 = easyfind(list, 128);
		std::cout << "Value found: " << *result3 << std::endl;
	} catch (const std::exception& e) {
		// 예외 처리
		std::cout << e.what() << std::endl;
	}

	try {
		// 없는 값을 찾는 예제
		std::list<int>::iterator result = easyfind(list, 6);
		std::cout << "Value found: " << *result << std::endl;
	} catch (const std::exception& e) {
		// 예외 처리
		std::cout << e.what() << std::endl;
	}

	return 0;
}