#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

Fixed::Fixed(void) {
	this->fixed_value = 0;
	std::cout << "Default Costructor Called " << std::endl;
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
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_value);
}