#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->setRawBits(0);
}

Fixed::Fixed(Fixed const& copy) 
{
    std::cout << "Copy constructor called" << std::endl;
    if (this != &copy)
        this->fixedPointValue = copy.fixedPointValue;
}

Fixed::Fixed(const int nb)
{
    std::cout << "Int constructor called" << std::endl;
    this->setRawBits(nb << this->fractionalBitsValue);
}

Fixed::Fixed(const float nb)
{
    std::cout << "Float constructor called" << std::endl;
    this->setRawBits((int)round(nb * (1 << this->fractionalBitsValue)));
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed	Fixed::operator=(Fixed const& copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->fixedPointValue = copy.getRawBits();
    return (*this);
}

Fixed   Fixed::operator+(Fixed const& copy) const 
{
    return (Fixed(this->toFloat() + copy.toFloat()));
}

Fixed   Fixed::operator-(Fixed const& copy) const
{
    return (Fixed(this->toFloat() - copy.toFloat()));
}

Fixed   Fixed::operator*(Fixed const& copy) const
{
    return (Fixed(this->toFloat() * copy.toFloat()));
}

Fixed   Fixed::operator/(Fixed const& copy) const
{
    return (Fixed( this->toFloat() / copy.toFloat()));
}

bool    Fixed::operator>(Fixed const& copy) const
{
    return (this->toFloat() > copy.toFloat());
}

bool    Fixed::operator<(Fixed const& copy) const
{
    return (this->toFloat() < copy.toFloat());
}

bool    Fixed::operator>=(Fixed const& copy) const
{
    return (this->toFloat() >= copy.toFloat());
}

bool           Fixed::operator<=(Fixed const& copy) const
{
    return (this->toFloat() <= copy.toFloat());
}

bool           Fixed::operator==(Fixed const& copy) const
{
    return (this->toFloat() == copy.toFloat());
}

bool           Fixed::operator!=(Fixed const& copy) const
{
    return (this->toFloat() != copy.toFloat());
}

Fixed          Fixed::operator++(void)
{
    Fixed   value;

    this->fixedPointValue++;
    value.setRawBits(this->getRawBits());
    return (value);
}

Fixed          Fixed::operator++(int nb)
{
    Fixed   value;

    (void)nb;
    this->fixedPointValue++;
    value.setRawBits(this->getRawBits());
    return ( value );
}

Fixed   Fixed::operator--(void)
{
    Fixed   value;

    this->fixedPointValue--;
    value.setRawBits(this->getRawBits());
    return ( value );
}

Fixed   Fixed::operator--(int nb)
{
    Fixed   value;

    (void)nb;
    this->fixedPointValue--;
    value.setRawBits(this->getRawBits());
    return ( value );
}

Fixed &   Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return (a);
    return (b);
}

const Fixed &   Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed &   Fixed::max(Fixed& a, Fixed& b) 
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed &   Fixed::max( const Fixed& a, const Fixed& b )
{
    if (a > b)
        return (a);
    return (b);
}

int	Fixed::getRawBits(void) const
{
    return (this->fixedPointValue);
}

void    Fixed::setRawBits(int const raw)
{
    this->fixedPointValue = raw;
}

int Fixed::toInt(void) const
{
    return (this->fixedPointValue >> this->fractionalBitsValue);
}

float   Fixed::toFloat(void) const
{
    return ((float)this->fixedPointValue / (1 << this->fractionalBitsValue));
}

std::ostream &  operator<<(std::ostream& stream, Fixed const& fixed)
{
    stream << fixed.toFloat();
    return (stream);
}