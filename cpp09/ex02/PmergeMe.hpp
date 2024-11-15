#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <vector>
# include <deque>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();

		int		getComparison();
		int		getSize();
		void	insert(char** data);
		void	sortVec();
		void	sortDeque();
		void	printVec();
		void	printDeque();
		
	private:
		PmergeMe(const PmergeMe& ref);
		PmergeMe& operator=(const PmergeMe& ref);

		std::vector<std::pair<int, int> >
			_sortVec_recursive(std::vector<std::pair<int,int> > &vec);
		std::deque<std::pair<int, int> >
			_sortDeque_recursive(std::deque<std::pair<int,int> > &deque);
		std::vector<std::pair<int, int> >
			_merge(std::vector<std::pair<int, int> > &main, std::vector<std::pair<int, int> > &sub);
		std::deque<std::pair<int, int> >
			_merge(std::deque<std::pair<int, int> > &main, std::deque<std::pair<int, int> > &sub);
		std::vector<std::pair<int, int> >
			_syncSubchain(std::vector<std::pair<int, int> > &main, std::vector<std::pair<int, int> > &sub);
		std::deque<std::pair<int, int> >
			_syncSubchain(std::deque<std::pair<int, int> > &main, std::deque<std::pair<int, int> > &sub);

		void 	_insert(std::vector<std::pair<int, int> > &main, std::pair<int, int> value, size_t limit);
		void 	_insert(std::deque<std::pair<int, int> > &main, std::pair<int, int> value, size_t limit);
		void	_syncIndex(std::vector<std::pair<int, int> > &oldVec, std::vector<std::pair<int, int> > &newVec);
		void	_syncIndex(std::deque<std::pair<int, int> > &oldDeque, std::deque<std::pair<int, int> > &newDeque);
		int		_compare(int a, int b, bool count);
		int		_getNextIdx(int currentComparisonCount);

		unsigned int		_comparison_count;
		std::vector<int>	_vec;
		std::deque<int>		_deque;
};

#endif