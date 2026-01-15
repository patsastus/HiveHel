#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <limits>

class Fixed {
	public:
		Fixed();
		Fixed(const int in);
		Fixed(const float f);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		static int getFractionalBits( void );

	private:
		int value_;
		static const int fractionalBits_ = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif // FIXED_HPP
