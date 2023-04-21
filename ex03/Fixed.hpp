#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

	private:
		int fixed_value;
		static const int fractional_bits;

	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed(void);
		Fixed(Fixed const & f);
		Fixed& operator=(Fixed const& f);

		bool operator>(Fixed const& f) const;
		bool operator<(Fixed const& f) const;
		bool operator>=(Fixed const& f) const;
		bool operator<=(Fixed const& f) const;
		bool operator==(Fixed const& f) const;
		bool operator!=(Fixed const& f) const;

		// Overload arithmetic operator
		float operator+(Fixed f) const;
		float operator-(Fixed f) const;
		float operator*(Fixed f) const;
		float operator/(Fixed f) const;

		// Overload increment/decrement operator
		Fixed operator++(); // Pre increment
		Fixed operator--(); // Pre Decrement
		Fixed operator++(int); // Post increment
		Fixed operator--(int); // Post decrement

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		static Fixed &min(Fixed &x, Fixed &y);
		static const Fixed &min(Fixed const &x, Fixed const &y);
		static Fixed &max(Fixed &x, Fixed &y);
		static const Fixed &max(Fixed const &x, Fixed const &y);
};

std::ostream& operator<<(std::ostream &output, const Fixed &fixed);

#endif