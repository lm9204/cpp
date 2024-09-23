#include <iostream>

#include "MutantStack.hpp"

int main()
{
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;
		mstack.pop();

		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	{
		MutantStack<int> mstack;

		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);
		mstack.push(6);
		mstack.push(7);
		mstack.push(8);

		const MutantStack<int> c_mstack = mstack;

		std::cout << "[Print Stack Value From Top]\n";
		size_t len = mstack.size();
		for (size_t i = 0; i < len; ++i)
		{
			std::cout << mstack.top() << std::endl;
			mstack.pop();
		}

		std::cout << "[Copy Stack Value]\n";
		for (MutantStack<int>::const_iterator cit = c_mstack.begin(); cit != c_mstack.end(); cit++) {
			std::cout << *cit << std::endl;
		}
	}
	return (0);
}