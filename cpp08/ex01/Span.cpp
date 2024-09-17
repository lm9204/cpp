#include <exception>

#include "Span.hpp"

Span::Span(unsigned int n) : _size(n)
{

}

Span::Span(const Span& ref)
{
	*this = ref;
}

Span& Span::operator=(const Span& ref)
{
	if (this == &ref)
		return *this;

	_size = ref._size;
	_elements = ref._elements;
	return *this;
}

Span::~Span()
{

}

void	Span::addNumber(int n)
{
	if (_elements.size() < _size)
		_elements.push_back(n);
	else
		throw std::out_of_range("out of range");
}

int		Span::shortestSpan()
{
	if (_elements.size() < 2)
		throw std::logic_error("Not enough elements to find a shortestspan");
	
	std::vector<int> sorted(_elements);
	std::sort(sorted.begin(), sorted.end());

	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 0; i < sorted.size() - 1; ++i)
	{
		int span = sorted[i + 1] - sorted[i];
		if (span < minSpan)
			minSpan = span;
	}
	
	return minSpan;
}

int		Span::longestSpan()
{
	if (_elements.size() < 2)
		throw std::logic_error("Not enough elements to find a longtestspan");
	
	std::vector<int> sorted(_elements);
	std::sort(sorted.begin(), sorted.end());

	return sorted.back() - sorted.front();
}
