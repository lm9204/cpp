#ifndef RPN_HPP
# define RPN_HPP
# include <string>
# include <stack>

class RPN
{
	public:
		RPN(std::string arg);
		~RPN();

		int checkSymbol(std::string element);
		int	isSymbol(std::string element);
		void	run();

	private:
		RPN();
		RPN(const RPN& ref);
		RPN& operator=(const RPN& ref);

		std::stack<int>	_data;

};

#endif