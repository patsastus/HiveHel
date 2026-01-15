#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include "Fixed.hpp"

// ANSI Color Codes
#define COLOR_GREEN "\033[32m"
#define COLOR_RED   "\033[31m"
#define COLOR_CYAN "\033[36m"
#define COLOR_RESET "\033[0m"


void printBool(bool res) {
    if (res)
        std::cout << COLOR_GREEN << std::setw(5) << "True" << COLOR_RESET;
    else
        std::cout << COLOR_RED << std::setw(5) << "False" << COLOR_RESET;
    std::cout << " | ";
}

void testOverUnderFlow() {
    std::cout << "\n=== Over/Underflow Tests (Clamping Check) ===\n" << std::endl;

	// min/max for 24.8 Fixed point is around +/- 8388608
    Fixed nearMax(8388600); 
    Fixed nearMin(-8388600);
    Fixed small(10);

    // TEST 1: Addition Overflow
    std::cout << "--- Test 1: Addition Overflow ---" << std::endl;
    Fixed resultAdd = nearMax + small;    
    std::cout << nearMax << " + " << small << " = " << resultAdd << std::endl;

    // TEST 2: Subtraction Underflow
    std::cout << "\n--- Test 2: Subtraction Underflow ---" << std::endl;
    Fixed resultSub = nearMin - small;
    std::cout << nearMin << " - " << small << " = " << resultSub << std::endl;

	// TEST 3: Multiplication Overflow
    std::cout << "\n--- Test 3: Multiplication Overflow ---" << std::endl;
    Fixed f1(5000);
    Fixed f2(2000);
    Fixed resultMult = f1 * f2;
    std::cout << f1 << " * " << f2 << " = " << resultMult << std::endl;
	
	// TEST 4 : Multiplication Underflow
	std::cout << "\n--- Test 4: Multiplication Underflow ---" << std::endl;
    Fixed f3(5000);
    Fixed f4(-2000);
    resultMult = f3 * f4;
    std::cout << f3 << " * " << f4 << " = " << resultMult << std::endl;
    
	// TEST 5: Division Overflow
    std::cout << "\n--- Test 5: Division Overflow ---" << std::endl;
    Fixed f5(5000000);
    Fixed f6(0.5f);
    Fixed resultDiv = f5 / f6;
    std::cout << f5 << " / " << f6 << " = " << resultDiv << std::endl;

	// TEST 6: Division Underflow
    std::cout << "\n--- Test 6: Division Overflow ---" << std::endl;
    Fixed f7(-5000000);
    Fixed f8(0.5f);
    resultDiv = f7 / f8;
    std::cout << f7 << " / " << f8 << " = " << resultDiv << std::endl;
}

void testComparisons() {
    Fixed a(10);      
    Fixed b(10.0f);   
	Fixed c(2);       
    
	Fixed* objs[] = {&a, &b, &c};
    std::string names[] = {"a (10)", "b (10.0)", "c (2)"};
	const int W_LBL = 22; // Width for the label column
	const int W_VAL = 5;  // Width for "True"/"False"

    std::cout << "\n=== Comparison Operator Tests ===\n" << std::endl;
	std::string h_line = std::string(W_LBL + 3, '-') + std::string(6 * (W_VAL + 3), '-') + "-";
    
    std::cout << h_line << std::endl;
    std::cout << "| " << std::setw(W_LBL) << "Compare" << " | " 
              << std::setw(W_VAL) << ">" << " | "
              << std::setw(W_VAL) << "<" << " | "
              << std::setw(W_VAL) << ">=" << " | "
              << std::setw(W_VAL) << "<=" << " | "
              << std::setw(W_VAL) << "==" << " | "
              << std::setw(W_VAL) << "!=" << " |" << std::endl;
    std::cout << h_line << std::endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::string label = names[i] + " vs " + names[j];
            std::cout << "| " << std::setw(W_LBL) << label << " | ";

            Fixed& lhs = *objs[i];
            Fixed& rhs = *objs[j];

            printBool(lhs > rhs);
            printBool(lhs < rhs);
            printBool(lhs >= rhs);
            printBool(lhs <= rhs);
            printBool(lhs == rhs);
            printBool(lhs != rhs);
            
            std::cout << std::endl;
        }
    }
    std::cout << h_line << std::endl;
}

void testArithmetic(){
	Fixed a(5.05f);
    Fixed b(2);
	Fixed c(1);
	Fixed d(3);
	Fixed e(-2);

    std::cout << "\n=== Arithmetic Operator Tests ===\n" << std::endl;
    std::cout << "Values: a = " << a << " (" << a.toInt() << ")" << std::endl;
    std::cout << "        b = " << b << " (" << b.toInt() << ")" << std::endl;
	std::cout << "        c = " << c << " (" << c.toInt() << ")" << std::endl;
 	std::cout << "        d = " << d << " (" << d.toInt() << ")" << std::endl;   
	std::cout << "---------------------------------------" << std::endl;
    std::cout << "| " << std::setw(15) << "Operation" << " | " 
              << std::setw(15) << "Result (Fixed)" << " | " << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    // Addition
    std::cout << "| " << std::setw(15) << "a + b" << " | " 
              << std::setw(15) << (a + b) << " |" << std::endl;

    // Subtraction (Both directions)
    std::cout << "| " << std::setw(15) << "a - b" << " | " 
              << std::setw(15) << (a - b) << " |" << std::endl;
    
    std::cout << "| " << std::setw(15) << "b - a" << " | " 
              << std::setw(15) << (b - a) << " |" << std::endl;

    // Multiplication
    std::cout << "| " << std::setw(15) << "a * b" << " | " 
              << std::setw(15) << (a * b) << " |" << std::endl;

    // Division 
    std::cout << "| " << std::setw(15) << "a / b" << " | " 
              << std::setw(15) << (a / b) << " |" << std::endl;

	std::cout << "| " << std::setw(15) << "a / -b" << " | " 
              << std::setw(15) << (a / e) << " |" << std::endl;

	// Division (other direction)
    std::cout << "| " << std::setw(15) << "b / a" << " | " 
              << std::setw(15) << (b / a) << " |" << std::endl;

	 std::cout << "| " << std::setw(15) << "-b / a" << " | " 
              << std::setw(15) << (e / a) << " |" << std::endl;

	//Division by one (should preserve everything)
	 std::cout << "| " << std::setw(15) << "b / c" << " | " 
              << std::setw(15) << (b / c) << " |" << std::endl;

	std::cout << "| " << std::setw(15) << "-b / c" << " | " 
              << std::setw(15) << (e / c) << " |" << std::endl;

	//Division that isn't exact should round to nearest Fixed, not floor
	Fixed f = b / d;
	std::cout << "| " << std::setw(15) << "b / d" << " | " 
              << std::setw(15) << f << " | " << --f << " | " << std::endl;

	f = e / d;
	std::cout << "| " << std::setw(15) << "-b / d" << " | " 
              << std::setw(15) << f << " |" << ++f << " | " << std::endl;



    std::cout << "---------------------------------------" << std::endl;
}

void testIncrements(){
	Fixed a;
      
    std::cout << "\n=== Increment/Decrement Tests ===\n" << std::endl;
    std::cout << "Starting with a = " << a << std::endl;
    std::cout << "Epsilon (smallest unit) is 1/" << (1 << Fixed::getFractionalBits());
	std::cout << " = " << (double)1 / (double)(1 << Fixed::getFractionalBits()) << std::endl;
    
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "| " << std::setw(15) << "Operation" << " | " 
              << std::setw(25) << "Result of Expression" << " | " 
              << std::setw(18) << "Value of 'a' after" << " |" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;

    // 1. Pre-Increment (++a)
    // 'a' increases, then the new value is returned.
    std::cout << "| " << std::setw(15) << "++a" << " | " 
              << std::setw(25) << ++a << " | " 
              << std::setw(18) << a << " |" << std::endl;

    // 2. Post-Increment (a++)
    // return old value, THEN 'a' increases.
    std::cout << "| " << std::setw(15) << "a++" << " | " 
              << std::setw(25) << a++ << " | " 
              << std::setw(18) << a << " |" << std::endl;

    // 3. Post-Decrement (a--)
    // Return old value, THEN 'a' decreases.
    std::cout << "| " << std::setw(15) << "a--" << " | " 
              << std::setw(25) << a-- << " | " 
              << std::setw(18) << a << " |" << std::endl;

    // 4. Pre-Decrement (--a)
    // 'a' decreases (back to 0), then return new value.
    std::cout << "| " << std::setw(15) << "--a" << " | " 
              << std::setw(25) << --a << " | " 
              << std::setw(18) << a << " |" << std::endl;

    std::cout << "------------------------------------------------------------------" << std::endl;	
	std::cout << "   Testing incremental overflow" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;	
	// 5. Test increment overflow (set a to max, do a++)
	a = Fixed(9000000);
    std::cout << "| " << std::setw(15) << "a = max, a++" << " | " 
              << std::setw(25) << a++ << " | " 
              << std::setw(18) << a << " |" << std::endl;

 	// 6. Test increment underflow (set a to min, a--)
	a = Fixed(-9000000);
    std::cout << "| " << std::setw(15) << "a = min, a--" << " | " 
              << std::setw(25) << a-- << " | " 
              << std::setw(18) << a << " |" << std::endl;


    std::cout << "------------------------------------------------------------------" << std::endl;	
}

void testMinMax(){
	std::cout << "\n=== Min/Max Function Tests ===\n" << std::endl;
    std::cout << std::fixed << std::setprecision(8);

    // ---------------------------------------------------------
    // TEST 1: Non-Const Objects
    // ---------------------------------------------------------
    std::cout << "--- Test 1: Non-Const Objects (Returns Mutable Reference) ---" << std::endl;
    Fixed a(10.5f);
    Fixed b(20.5f);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    Fixed& minRes = Fixed::min(a, b);
    Fixed& maxRes = Fixed::max(a, b);

    std::cout << "Fixed::min(a, b) = " << COLOR_CYAN << minRes << COLOR_RESET << std::endl;
    std::cout << "Fixed::max(a, b) = " << COLOR_CYAN << maxRes << COLOR_RESET << std::endl;

    std::cout << "[Check]: Modifying the result of max(a,b) to 999..." << std::endl;
    maxRes = Fixed(999); 
    std::cout << "Value of b is now: " << b << std::endl;


    // ---------------------------------------------------------
    // TEST 2: Const Objects
    // ---------------------------------------------------------
    std::cout << "\n--- Test 2: Const Objects (Returns Read-Only Reference) ---" << std::endl;
    
    // Create const copies
    const Fixed c(5.5f);
    const Fixed d(2.5f);

    std::cout << "c (const) = " << c << std::endl;
    std::cout << "d (const) = " << d << std::endl;

    const Fixed& constMin = Fixed::min(c, d);
    const Fixed& constMax = Fixed::max(c, d);

    std::cout << "Fixed::min(c, d) = " << COLOR_CYAN << constMin << COLOR_RESET << std::endl;
    std::cout << "Fixed::max(c, d) = " << COLOR_CYAN << constMax << COLOR_RESET << std::endl;

    // Uncommenting the line below causes compiler error
    // constMax = Fixed(1234); 
  
    std::cout << "----------------------------------------------" << std::endl;
}

int main( void ) {
	std::cout << std::fixed << std::setprecision(8); //set floats to always print with 8 decimal points, which displays full precision for our Fixed
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}	
	testComparisons();
	testArithmetic();
	testIncrements();
	testMinMax();
	testOverUnderFlow();
	return 0;
}
