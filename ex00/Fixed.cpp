#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPointValue = 0;
}

Fixed::Fixed( Fixed const & copy )
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixedPointValue = copy.fixedPointValue;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator = (const Fixed & copy)
{
	std::cout << "Assignation operator called" << std::endl;
	this->fixedPointValue = copy.fixedPointValue;
	return (*this);
}

int		Fixed::getRawBits( void )
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointValue);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointValue = raw;
}
