#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span
{
	public:
		Span(unsigned int n);
		Span(const Span& ref);
		Span& operator=(const Span& ref);
		~Span();

		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();


	private:
		Span();

		unsigned int		_size;
		std::vector<int>	_elements;

};

#endif