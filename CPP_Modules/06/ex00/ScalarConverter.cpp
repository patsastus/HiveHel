#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    if (this != &other) {       
    }
    return *this;
}

ScalarConverter::~ScalarConverter() { 
}


void convert(std::string const &literal){
	char c, long l, float f, double d, size_t which = 5;

	if (literal.length() == 3 && literal.front() == '\'' && literal.back() == '\''){
		c = literal[1];
		which = 0;
	} else 

	
}
