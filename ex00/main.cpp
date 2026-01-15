#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;
	b.setRawBits(42);
	c = b;
	b.setRawBits(21);
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	//testing self-assignment requires a workaround when compiling with -Werror, this is 'a = a;'
	Fixed *ptr1 = &a;
	Fixed *ptr2 = &a;
	*ptr1 = *ptr2; 
	return 0;
}
