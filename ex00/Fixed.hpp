#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

	private:
		int fixed_value;
		static const int fractional_bits;

	public:
		Fixed(void);
		~Fixed(void);
		Fixed(Fixed const & f);
		Fixed& operator=(Fixed const& f);

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif