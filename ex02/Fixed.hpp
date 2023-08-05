#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <fstream>
# include <cmath>

class Fixed 
{
    private:
        int                 fixedPointValue;
        static const int    fractionalBitsValue = 8;

    public:
        Fixed( void );
        Fixed( Fixed const& copy );
        Fixed( const int num );
        Fixed( const float num );
        ~Fixed( void );

        Fixed   operator+( Fixed const& rhs ) const;
        Fixed   operator-( Fixed const& rhs ) const;
        Fixed   operator*( Fixed const& rhs ) const;
        Fixed   operator/( Fixed const& rhs ) const;

        Fixed   operator=( Fixed const& rhs );
        
        Fixed   operator++( void );
        Fixed   operator++( int );
        Fixed   operator--( void );
        Fixed   operator--( int );
        
        bool   operator>( Fixed const& rhs ) const;
        bool   operator<( Fixed const& rhs ) const;
        bool   operator>=( Fixed const& rhs ) const;
        bool   operator<=( Fixed const& rhs ) const;
        bool   operator==( Fixed const& rhs ) const;
        bool   operator!=( Fixed const& rhs ) const;

        static Fixed&  min( Fixed& a, Fixed& b );
        static const Fixed&    min( const Fixed& a, const Fixed& b );
        
        static Fixed&  max( Fixed& a, Fixed& b );
        static const Fixed&    max( const Fixed& a, const Fixed& b );

        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        int     toInt( void ) const;
        float   toFloat( void ) const;
};
std::ostream&   operator<<( std::ostream& stream, Fixed const& fixed );

#endif