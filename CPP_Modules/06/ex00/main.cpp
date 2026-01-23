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
	if (argc == 1)
		testCases();
	else if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else
		std::cout << "Usage :" << argv[0] << "[string to be converted]" << std::endl;
	return 0;
}
