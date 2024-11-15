#include <iostream>
#include <exception>
#include <cstdlib>
#include <sys/time.h>
#include <unistd.h>

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc <= 1)
		return (1);

	try
	{
		struct timeval	vec_start, vec_end, deque_start, deque_end;
		PmergeMe ford;

		ford.insert(&argv[1]);
		std::cout << "Before:";
		ford.printVec();
		gettimeofday(&vec_start, NULL);
		ford.sortVec();
		gettimeofday(&vec_end, NULL);
		gettimeofday(&deque_start, NULL);
		ford.sortDeque();
		gettimeofday(&deque_end, NULL);
		std::cout << "After[Vector]:";
		ford.printVec();
		std::cout << "After[Deque]:";
		ford.printDeque();
		std::cout << "Sort Vector Time["<< ford.getSize() <<"]: " << (vec_end.tv_sec - vec_start.tv_sec) * 1000000 + vec_end.tv_usec - vec_start.tv_usec << " us\n";
		std::cout << "Sort Deque Time["<< ford.getSize() <<"]: " << (deque_end.tv_sec - deque_start.tv_sec) * 1000000 + deque_end.tv_usec - deque_start.tv_usec << " us\n";
		std::cout << "Total Comparison:" << ford.getComparison() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}