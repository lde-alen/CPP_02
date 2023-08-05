#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <fstream>
# include <cmath>

class Fixed {
    private:
        int                 fixedPointValue;
        static const int    fractionalBitsValue = 8;

    public:
        Fixed( void );
        Fixed( Fixed const& copy );
        Fixed( const int num );
        Fixed( const float num );
        ~Fixed( void );

        Fixed&  operator=( Fixed const& copy );
        Fixed   operator+( Fixed const& rhs ) const;
        Fixed   operator-( Fixed const& rhs ) const;
        Fixed   operator*( Fixed const& rhs ) const;
        Fixed   operator/( Fixed const& rhs ) const;

        int     getNum( float raw );
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        int     toInt( void ) const;
        float   toFloat( void ) const;
};

std::ostream&   operator<<( std::ostream& stream, Fixed const& fixed );

#endif