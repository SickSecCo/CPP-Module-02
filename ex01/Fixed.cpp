#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

Fixed::Fixed(void) {
	this->fixed_value = 0;
	std::cout << "Default Costructor Called " << std::endl;
}

/* A constructor that takes a constant integer value and converts
it into to the corresponding fixed value by left shifting the value
passed as parameter by the const int fractional bits (8) */
Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;;
	this->fixed_value = value << this->fractional_bits;
}

/* A constructor that takes a constant float value and converts
it into to the corresponding fixed value by multipling the value
passed as parameter with the left shifting fractional bits and rounding
the result */
Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->fixed_value = roundf(value * (1 << this->fractional_bits));
}

Fixed::~Fixed(void) {
	std::cout << "Destructor Called" << std::endl;
}

Fixed::Fixed(Fixed const & f) {
	std::cout << "Copy costructor called" << std::endl;
	fixed_value = f.fixed_value;
}

Fixed &Fixed::operator=(Fixed const &f) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_value = f.getRawBits();
	return *this;
}

void Fixed::setRawBits(int const raw) {
	this->fixed_value = raw;
}

int Fixed::getRawBits(void) const {
	return (this->fixed_value);
}

float Fixed::toFloat(void) const {
	return ((float)this->fixed_value/(float)(1 << this->fractional_bits));
}

int Fixed::toInt(void) const {
	return (this->fixed_value >> this->fractional_bits);
}

std::ostream& operator<<(std::ostream &output, const Fixed &fixed) {
	output << fixed.toFloat();
	return (output);
}