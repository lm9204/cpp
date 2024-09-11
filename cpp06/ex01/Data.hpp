#ifndef DATA_HPP
# define DATA_HPP
# include <iostream>

class Data
{
	public:
		Data();
		Data(const Data& ref);
		Data&	operator=(const Data& ref);
		~Data();

		std::string getName() const;
		void		setName(std::string name);

	private:
		std::string _name;
};

#endif