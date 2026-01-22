#include <iostream>
#include "ScalarConverter.hpp"
#define COLOR_GREEN "\033[32m"
#define COLOR_RESET "\033[0m" 

void testCases() {
	std::cout << COLOR_GREEN << "Running some test cases" << std::endl;
	{
	
		std::cout << "input characters" << COLOR_RESET << std::endl;
		std::string tests[] = {"'c'", "'X'", "' '", "'7'", "'~'"};
		for (int i=0; i < tests.size(); ++i){		
			ScalarConverter::convert(tests[i]);
		}
	}
}

int main(int argc, char *argv[]) {
	if (argc != 2)
		testCases();
	else 
		ScalarConverter::convert(argv[1]);
	return 0;
}
