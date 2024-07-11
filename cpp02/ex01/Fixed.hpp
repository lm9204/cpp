#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float floatN);
		~Fixed();
		Fixed(const Fixed &ref);
		Fixed &operator=(const Fixed &ref);
		friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

		int		getRawBits(void) const;
		int		toInt(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;


	private:
		static const int	_fract_bits = 8;
		int					_fixedN;


};

#endif