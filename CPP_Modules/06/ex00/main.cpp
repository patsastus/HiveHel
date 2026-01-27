#include <iostream>
#include "ScalarConverter.hpp"
#define COLOR_GREEN "\033[32m"
#define COLOR_RESET "\033[0m" 

void testCases() {
	std::cout << COLOR_GREEN << "Running some test cases" << std::endl;
	{
	
		std::cout  << std::endl<< "input characters" << COLOR_RESET << std::endl;
		std::string tests[] = {"'c'", "'X'", "' '", "'7'", "'~'", "f"};
		int len = 6;
		for (int i=0; i < len; ++i){		
			ScalarConverter::convert(tests[i]);
		}
	}
	{
		std::cout  << std::endl<< COLOR_GREEN << "input ints" << COLOR_RESET << std::endl;
		std::string tests[] = {"0", "-42", "+42", "2147483647", "-2147483648", 
			"9223372036854775807","-9223372036854775809"};
		int len = 7;
		for (int i=0; i < len; ++i){		
			ScalarConverter::convert(tests[i]);
		}
	}
	{
		std::cout  << std::endl<< COLOR_GREEN << "input floats" << COLOR_RESET << std::endl;
		std::string tests[] = {"0.0f", "-42.0f", "+42.0f", "2147483647.0f", "-2147483648.0f",
		   	"9223372036854775807.0f","-9223372036854775809.0f", "+inff", "-inff", "nanf"};
		int len = 10;
		for (int i=0; i < len; ++i){		
			ScalarConverter::convert(tests[i]);
		}
	}
	{
		std::cout  << std::endl<< COLOR_GREEN << "input doubles" << COLOR_RESET << std::endl;
		std::string tests[] = {"0", "-42.0", "+42.0", "2147483647.0", "-2147483648.0",
		   	"9223372036854775807.0","-9223372036854775809.0", "+inf", "-inf", "nan"};
		int len = 10;
		for (int i=0; i < len; ++i){		
			ScalarConverter::convert(tests[i]);
		}
	}
}

int main(int argc, char *argv[]) {
	if (argc == 1)
		testCases();
	else if (argc == 2){
		std::cout << "Using string [" << argv[1] << "]" << std::endl;
		ScalarConverter::convert(argv[1]);
	}
	else
		std::cout << "Usage :" << argv[0] << "[string to be converted] (if no string is supplied, runs standard set of tests)" << std::endl;
	return 0;
}
