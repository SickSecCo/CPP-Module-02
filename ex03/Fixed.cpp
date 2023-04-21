#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

Fixed::Fixed(void): fixed_value(0){}

/* A constructor that takes a constant integer value and converts
it into to the corresponding fixed value by left shifting the value
passed as parameter by the const int fractional bits (8) */
Fixed::Fixed(const int value) {
	this->fixed_value = value << this->fractional_bits;
}

/* A constructor that takes a constant float value and converts
it into to the corresponding fixed value by multipling the value
passed as parameter with the left shifting fractional bits and rounding
the result */
Fixed::Fixed(const float value) {
	this->fixed_value = roundf(value * (1 << this->fractional_bits));
}

Fixed::~Fixed(void) {}

Fixed::Fixed(Fixed const & f) {
	fixed_value = f.fixed_value;
}

Fixed &Fixed::operator=(Fixed const &f) {
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

bool Fixed::operator>(Fixed const &f) const {
	return (this->toFloat() > f.toFloat());
}

bool Fixed::operator<(Fixed const &f) const {
	return (this->toFloat() < f.toFloat());
}

bool Fixed::operator<=(Fixed const &f) const {
	return (this->toFloat() <= f.toFloat());
}

bool Fixed::operator>=(Fixed const &f) const {
	return (this->toFloat() >= f.toFloat());
}

bool Fixed::operator==(Fixed const &f) const {
	return (this->toFloat() == f.toFloat());
}

bool Fixed::operator!=(Fixed const &f) const {
	return (this->toFloat() != f.toFloat());
}

float Fixed::operator+(Fixed f) const {
	float temp = this->toFloat() + f.toFloat();
	return temp;
}

float Fixed::operator-(Fixed f) const {
	float temp = this->toFloat() - f.toFloat();
	return temp;
}

float Fixed::operator*(Fixed f) const {
	float temp = this->toFloat() * f.toFloat();
	return temp;
}

float Fixed::operator/(Fixed f) const {
	float temp = this->toFloat() / f.toFloat();
	return temp;
}

Fixed Fixed::operator++() {
	++this->fixed_value;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	++this->fixed_value;
	return(temp);
}

Fixed Fixed::operator--() {
	--this->fixed_value;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	--this->fixed_value;
	return(temp);
}


Fixed &Fixed::min(Fixed &x, Fixed &y) {
	if (x < y)
		return x;
	else
		return y;
}

const Fixed &Fixed::min(Fixed const &x, Fixed const &y) {

	if (x < y)
		return x;
	else
		return y;
}

Fixed &Fixed::max(Fixed &x, Fixed &y) {
	if (x > y)
		return x;
	else
		return y;
}

const Fixed &Fixed::max(Fixed const &x, Fixed const &y) {
	if (x > y)
		return (x);
	else
		return (y);
}