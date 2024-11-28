#include <iostream>
#include <sstream>
#include <exception>

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _comparison_count(0) {}

PmergeMe::~PmergeMe() {}

int		PmergeMe::getComparison()
{
	return _comparison_count;
}

int		PmergeMe::getSize()
{
	return _vec.size();
}

void	PmergeMe::insert(char** data)
{
	if (data == NULL)
		throw std::invalid_argument("Error. No arguments given.");

	int i = 0, n;
	while (data[i])
	{
		std::stringstream	ss(data[i]);
		while (!ss.eof())
		{
			ss >> n;
			if (ss.fail())
				throw std::invalid_argument("Error. Invalid Argument Type");
			if (n < 0)
				throw std::invalid_argument("Error. Only positive numbers are allowed");
			_vec.push_back(n);
			_deque.push_back(n);
		}
		++i;
	}
}

void	PmergeMe::sortVec()
{
	std::vector<std::pair<int, int> > vec;

	for (size_t i = 0; i < _vec.size(); ++i)
		vec.push_back(std::make_pair(_vec[i], 0));

	vec = _sortVec_recursive(vec);
	_vec.clear();

	for (size_t i = 0; i < vec.size(); ++i)
		_vec.push_back(vec[i].first);
}

void	PmergeMe::sortDeque()
{
	std::deque<std::pair<int, int> > deque;

	for (size_t i = 0; i < _deque.size(); ++i)
		deque.push_back(std::make_pair(_deque[i], 0));

	deque = _sortDeque_recursive(deque);
	_deque.clear();

	for (size_t i = 0; i < deque.size(); ++i)
		_deque.push_back(deque[i].first);
}

void	PmergeMe::printVec()
{
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << _vec[i] << " ";
	std::cout << "\n";
}

void	PmergeMe::printDeque()
{
	for (size_t i = 0; i < _deque.size(); ++i)
		std::cout << _deque[i] << " ";
	std::cout << "\n";
}

/* =========================================================================
 * 								private
 * ========================================================================= */

std::vector<std::pair<int, int> >
PmergeMe::_sortVec_recursive(std::vector<std::pair<int,int> > &vec)
{
	int n = vec.size();
	if (n == 1)
		return vec;

	int mid = n / 2;
	std::vector<std::pair<int, int> > mainC, subC, nMainC;

	// 두 명씩 짝을 지어 비교하여 큰 값(메인 체인)과 작은 값(서브 체인)을 함께 관리
	for (int i = 0; i < mid; ++i)
	{
		int larger = _compare(vec[2 * i].first, vec[2 * i + 1].first, true);
		int smaller = (vec[2 * i].first == larger) ? vec[2 * i + 1].first : vec[2 * i].first;
		mainC.push_back(std::make_pair(larger, i * 2));
		subC.push_back(std::make_pair(smaller, i * 2 + 1));
	}

	if (n % 2 == 1) // 홀수인 경우 마지막 남은 값은 메인 체인에 추가
		subC.push_back(std::make_pair(vec[n - 1].first, n - 1));

	nMainC = _sortVec_recursive(mainC);
	
	std::vector<std::pair<int, int> > sub;

	_syncIndex(mainC, nMainC);
	sub = _syncSubchain(nMainC, subC);

	return _merge(nMainC, sub);
}

std::deque<std::pair<int, int> >
PmergeMe::_sortDeque_recursive(std::deque<std::pair<int,int> > &deque)
{
	int n = deque.size();
	if (n == 1)
		return deque;

	int mid = n / 2;
	std::deque<std::pair<int, int> > mainC, subC, nMainC;

	// 두 명씩 짝을 지어 비교하여 큰 값(메인 체인)과 작은 값(서브 체인)을 함께 관리
	for (int i = 0; i < mid; ++i)
	{
		int larger = _compare(deque[2 * i].first, deque[2 * i + 1].first, false);
		int smaller = (deque[2 * i].first == larger) ? deque[2 * i + 1].first : deque[2 * i].first;
		mainC.push_back(std::make_pair(larger, i * 2));
		subC.push_back(std::make_pair(smaller, i * 2 + 1));
	}

	if (n % 2 == 1) // 홀수인 경우 마지막 남은 값은 메인 체인에 추가
		subC.push_back(std::make_pair(deque[n - 1].first, n - 1));

	nMainC = _sortDeque_recursive(mainC);
	
	std::deque<std::pair<int, int> > sub;

	_syncIndex(mainC, nMainC);
	sub = _syncSubchain(nMainC, subC);

	return _merge(nMainC, sub);
}

std::vector<std::pair<int, int> >
PmergeMe::_merge(std::vector<std::pair<int, int> > &main, std::vector<std::pair<int, int> > &sub)
{
	size_t prevCountIdx = 1, currIdx = 2, prevComparisonCount = 2, insertCount = 1, len = sub.size();
	if (len > 0)
		main.insert(main.begin(), sub[0]);

	for (size_t i = 0; i < len; ++i)
	{
		if (currIdx >= len)
			currIdx = len - 1;
		for (size_t j = currIdx; j >= prevCountIdx; --j)
		{
			_insert(main, sub[j], j + insertCount);
			insertCount++;
		}
		prevCountIdx = currIdx + 1;
		currIdx = _getNextIdx(++prevComparisonCount);
	}

	return main;
}

std::deque<std::pair<int, int> >
PmergeMe::_merge(std::deque<std::pair<int, int> > &main, std::deque<std::pair<int, int> > &sub)
{
	size_t prevCountIdx = 1, currIdx = 2, prevComparisonCount = 2, insertCount = 1, len = sub.size();
	if (len > 0)
		main.insert(main.begin(), sub[0]);

	for (size_t i = 0; i < len; ++i)
	{
		if (currIdx >= len)
			currIdx = len - 1;
		for (size_t j = currIdx; j >= prevCountIdx; --j)
		{
			_insert(main, sub[j], j + insertCount);
			insertCount++;
		}
		prevCountIdx = currIdx + 1;
		currIdx = _getNextIdx(++prevComparisonCount);
	}

	return main;
}

std::vector<std::pair<int, int> >
PmergeMe::_syncSubchain(std::vector<std::pair<int, int> > &main, std::vector<std::pair<int, int> > &sub)
{
	std::vector<std::pair<int, int> >	result;

	for (size_t i = 0; i < main.size(); ++i)
	{
		for (std::vector<std::pair<int, int> >::iterator it = sub.begin(); it != sub.end();)
		{
			if (it->second / 2 == main[i].second / 2)
			{
				result.push_back(*it);
				it = sub.erase(it);
				break;
			}
			else
				++it;
		}
	}
	if (sub.begin() != sub.end())
		result.push_back(sub.back());

	return result;
}

std::deque<std::pair<int, int> >
PmergeMe::_syncSubchain(std::deque<std::pair<int, int> > &main, std::deque<std::pair<int, int> > &sub)
{
	std::deque<std::pair<int, int> >	result;

	for (size_t i = 0; i < main.size(); ++i)
	{
		for (std::deque<std::pair<int, int> >::iterator it = sub.begin(); it != sub.end();)
		{
			if (it->second / 2 == main[i].second / 2)
			{
				result.push_back(*it);
				it = sub.erase(it);
				break;
			}
			else
				++it;
		}
	}
	if (sub.begin() != sub.end())
		result.push_back(sub.back());

	return result;
}

void	PmergeMe::_syncIndex(std::vector<std::pair<int, int> > &oldVec, std::vector<std::pair<int, int> > &newVec)
{
	for (size_t i = 0; i < newVec.size(); ++i)
	{
		for (std::vector<std::pair<int, int> >::iterator it = oldVec.begin(); it != oldVec.end();)
		{
			if (it->first == newVec[i].first)
			{
				newVec[i].second = it->second;
				it = oldVec.erase(it);
				break;
			}
			else
				++it;
		}
	}
}

void	PmergeMe::_syncIndex(std::deque<std::pair<int, int> > &oldDeque, std::deque<std::pair<int, int> > &newDeque)
{
	for (size_t i = 0; i < newDeque.size(); ++i)
	{
		for (std::deque<std::pair<int, int> >::iterator it = oldDeque.begin(); it != oldDeque.end();)
		{
			if (it->first == newDeque[i].first)
			{
				newDeque[i].second = it->second;
				it = oldDeque.erase(it);
				break;
			}
			else
				++it;
		}
	}
}

void 	PmergeMe::_insert(std::vector<std::pair<int, int> > &main, std::pair<int, int> value, size_t limit)
{
	int left = 0, right = limit; // 메인 체인에서 앞부분만 탐색
	int mid = (left + right) / 2;
	while (left != right)
	{
		_comparison_count++;
		if (main[mid].first == value.first)
			break;
		else if (main[mid].first < value.first)
			left = mid + 1;
		else if (main[mid].first > value.first)
			right = mid;
		mid = (left + right) / 2;
	}
	main.insert(main.begin() + mid	, value); // 적절한 위치에 삽입
}

void 	PmergeMe::_insert(std::deque<std::pair<int, int> > &main, std::pair<int, int> value, size_t limit)
{
	int left = 0, right = limit; // 메인 체인에서 앞부분만 탐색
	int mid = (left + right) / 2;
	while (left != right)
	{
		if (main[mid].first == value.first)
			break;
		else if (main[mid].first < value.first)
			left = mid + 1;
		else if (main[mid].first > value.first)
			right = mid;
		mid = (left + right) / 2;
	}
	main.insert(main.begin() + mid	, value); // 적절한 위치에 삽입
}

int		PmergeMe::_compare(int a, int b, bool count)
{
	if (count)
		_comparison_count++;
	return (a > b) ? a : b;
}

int		PmergeMe::_getNextIdx(int currentComparisonCount)
{
	if (currentComparisonCount == 2)
				return 3;
	/* t_j = (2^(j+1) + (-1)^j) / 3 */ 
	int j = currentComparisonCount, t_current;
	for (int k = 3; k <= j; ++k)
		t_current = (pow(2, k + 1) + (int)pow(-1, k)) / 3;
	
	return t_current - 1;
}