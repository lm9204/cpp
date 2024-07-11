#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &ref);
		Fixed &operator=(const Fixed &ref);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		static const int	_fract_bits = 8;
		int					_fixedN;


};

#endif