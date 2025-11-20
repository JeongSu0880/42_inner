#include "Fixed.hpp"

Fixed::Fixed() : value(0) { 
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
 }

Fixed::Fixed(const Fixed &fixed) { 
	std::cout << "Copy constructor called" << std::endl;
	
	this->value = fixed.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &fixed) {
		value = fixed.getRawBits();
	} 
	return *this;
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;

	value = num << this->FRACTIONAL_BITS;
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;

	value = roundf(num * (1 << this->FRACTIONAL_BITS));
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;

	return value;
}

void	Fixed::setRawBits(const int raw) {
	value = raw;
}

float	Fixed::toFloat() const {
	return (this->value / static_cast<float>((1 << this->FRACTIONAL_BITS)));
}

int Fixed::toInt() const {
	return (this->value >> this->FRACTIONAL_BITS);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixNum) {
	
	out << fixNum.toFloat();
	
	return out;
}
