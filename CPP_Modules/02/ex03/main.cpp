#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

// ANSI Color Codes
#define COLOR_GREEN "\033[32m"
#define COLOR_RED   "\033[31m"
#define COLOR_RESET "\033[0m"

bool bsp( Point const a, Point const b, Point const c, Point const point );

void printBool(bool res) {
    if (res)
        std::cout << COLOR_GREEN << "True" << COLOR_RESET;
    else
        std::cout << COLOR_RED << "False" << COLOR_RESET;
}

int main() {
    Point a(0.0f, 0.0f);
    Point b(20.0f, 0.0f);
    Point c(10.0f, 20.0f);

    std::cout << "A("<< a.getX()<<","<<a.getY() <<"), B(" <<b.getX() <<","<<b.getY() <<"), C("<<c.getX() <<","<<c.getY() <<")" << std::endl << std::endl;
   
    // Y loops from High to Low because terminal prints Top-to-Bottom
    for (int y = 25; y >= -2; y--) {
        if (y % 5 == 0) std::cout << y << "\t";
        else std::cout << "\t";

        for (int x = -2; x <= 25; x++) {
            Point p((float)x, (float)y);
            bool result = bsp(a, b, c, p);
           	if (x == a.getX().toInt() && y == a.getY().toInt()) {
                std::cout << "A ";
			} else if (x == b.getX().toInt() && y == b.getY().toInt()) {
				std::cout << "B ";
			} else if (x == c.getX().toInt() && y == c.getY().toInt()) {
				std::cout << "C ";
			}
			else if (result == true) {
                std::cout << "I ";
            }
            else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "\t ";
    for(int x = -2; x <= 25; x++) {
        if (x % 5 == 0) std::cout << x;
        else std::cout << "  ";
    }
    std::cout << std::endl;

	//Testing points on edge AB, right inside, and right outside
	std::cout << "Testing points on or near boundary AB" << std::endl;
	{
	Point test(5.0f, 0.0f);
	std::cout << "Point " << test.getX() << "," << test.getY() << " returns " ;
	printBool(bsp(a,b,c,test)) ;
	std::cout<< std::endl;
	}
	{
	Fixed x(5.0f);
	Fixed y;
	Point test(x, ++y);
	std::cout << "Point " << test.getX() << "," << test.getY() << " returns " ;
	printBool(bsp(a,b,c,test));
	std::cout<< std::endl;
	}
	{
	Fixed x(5.0f);
	Fixed y;
	Point test(x, --y);
	std::cout << "Point " << test.getX() << "," << test.getY() << " returns " ;
	printBool(bsp(a,b,c,test));
	std::cout << std::endl;
	}

	//Testing points on edge AC, right inside, and right outside	
	std::cout << "Testing points on or near boundary AC" << std::endl;
	{
	Point test(5.0f, 10.0f);
	std::cout << "Point " << test.getX() << "," << test.getY() << " returns " ;
	printBool(bsp(a,b,c,test));
	std::cout << std::endl;
	}
	{
	Fixed x(5.0f);
	Fixed y(10.0f);
	Point test(++x, y);
	std::cout << "Point " << test.getX() << "," << test.getY() << " returns " ;
	printBool(bsp(a,b,c,test));
	std::cout << std::endl;
	}
	{
	Fixed x(5.0f);
	Fixed y(10.0f);
	Point test(--x, y);
	std::cout << "Point " << test.getX() << "," << test.getY() << " returns " ;
	printBool(bsp(a,b,c,test));
	std::cout << std::endl;
	}
	
	//Testing points on edge BC, right inside, and right outside	
	std::cout << "Testing points on or near boundary BC" << std::endl;
	{
	Point test(15.0f, 10.0f);
	std::cout << "Point " << test.getX() << "," << test.getY() << " returns " ;
	printBool(bsp(a,b,c,test));
	std::cout << std::endl;
	}
	{
	Fixed x(15.0f);
	Fixed y(10.0f);
	Point test(--x, y);
	std::cout << "Point " << test.getX() << "," << test.getY() << " returns " ;
	printBool(bsp(a,b,c,test));
	std::cout << std::endl;
	}
	{
	Fixed x(15.0f);
	Fixed y(10.0f);
	Point test(++x, y);
	std::cout << "Point " << test.getX() << "," << test.getY() << " returns " ;
	printBool(bsp(a,b,c,test));
	std::cout << std::endl;
	}

    return 0;
}

