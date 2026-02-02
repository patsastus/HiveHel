#include <iostream>
#include "whatever.hpp"
#define COLOR_GREEN "\033[32m"
#define COLOR_RESET "\033[0m" 

int main() {
	int a = 2, b = 3;
	std::cout << COLOR_GREEN << "Originial state: " << COLOR_RESET << "a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << COLOR_GREEN << "Swapped state: " << COLOR_RESET << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1", d = "chaine2";
	std::cout << COLOR_GREEN << "Originial state: " << COLOR_RESET << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << COLOR_GREEN << "Swapped state: " << COLOR_RESET << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}
