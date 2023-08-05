#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					fixedPointValue;
		static const int	fractionalBitsValue = 8;

	public:
		Fixed( void );
		Fixed( Fixed const & copy );
		~Fixed( void );
		Fixed & operator = (const Fixed & copy);
		int		getRawBits( void );
		void	setRawBits( int const raw );
};

# endif