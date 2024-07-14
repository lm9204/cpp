#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float floatN);
		~Fixed();
		Fixed(const Fixed& ref);

		bool	operator>(const Fixed& ref) const;
		bool	operator<(const Fixed& ref) const;
		bool	operator>=(const Fixed& ref) const;
		Fixed&	operator=(const Fixed& ref);
		bool	operator<=(const Fixed& ref) const;
		bool	operator==(const Fixed& ref) const;
		bool	operator!=(const Fixed& ref) const;
		Fixed	operator+(const Fixed& ref) const;
		Fixed	operator-(const Fixed& ref) const;
		Fixed	operator*(const Fixed& ref) const;
		Fixed	operator/(const Fixed& ref) const;
		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);
		friend	std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

		int		getRawBits(void) const;
		int		toInt(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;

		static const Fixed&	min(const Fixed& r1, const Fixed& r2);
		static Fixed&		min(Fixed& r1,  Fixed& r2);
		static const Fixed&	max(const Fixed& r1, const Fixed& r2);
		static Fixed&		max(Fixed& r1, Fixed& r2);

	private:
		static const int	_fract_bits = 8;
		int					_fixedN;

};

#endif