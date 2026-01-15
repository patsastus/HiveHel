#include <iostream>
#include <iomanip>
#include "Fixed.hpp"

int main( void ) {
	{
		Fixed a;
		Fixed const b( 10 );
		Fixed const c( 42.42f );
		Fixed const d( b );
		a = Fixed( 1234.4321f );
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;
		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}
	{
		//testing some overflows
		std::cout << std::endl << "**Testing overflows**" << std::endl;
		std::cout << std::fixed << std::setprecision(8);
		float overMax = 1e15f, underMin = -1e15f;
		int overTol = 9000000, underTol = -9000000;
		Fixed overFloat(overMax);
		Fixed underFloat(underMin);
		Fixed overInt(overTol);
		Fixed underInt(underTol);
		std::cout << "Float overflow results in " << overFloat << std::endl;
		std::cout << "Float underflow results in " << underFloat << std::endl;
		std::cout << "Int overflow results in " << overInt << std::endl;
		std::cout << "Int underflow results in " << underInt << std::endl;
	}
	return 0;
}
