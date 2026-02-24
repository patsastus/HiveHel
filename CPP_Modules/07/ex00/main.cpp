#include <iostream>
#include "whatever.hpp"
#define COLOR_GREEN "\033[32m"
#define COLOR_RESET "\033[0m"

//for testing that the min and max functions return the latter object when comparators are equal
struct Test{
    int     value_;
    char    ID_;

    bool operator<(const Test &other) const{
        return value_ < other.value_;
    };
    bool operator>(const Test &other) const{
        return value_ > other.value_;
    };
};

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

	Test e{3, 'a'}, f{3,'b'};
	std::cout << COLOR_GREEN << "Checking that latter object is returned when equal: " << COLOR_RESET <<std::endl;
	Test min = ::min(e,f);
	Test max = ::max(e,f);
	std::cout << "ID of min({3,'a'}, {3,'b'}): '"<< min.ID_ << "', ID of max({3,'a'},{3,'b'}): '"<< max.ID_ <<"'"<<std::endl;

	return 0;
}
