#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <iomanip>

class ScalarConverter {
//private constructors make the class uninstantiable.
private: 
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

	enum InputType {
		Char = 0,
		Int,
		Float,
		Double,
		Error
	};

	struct Values {
		char 	c;
		int		i;
		float 	f;
		double 	d;
		bool	possible[4];
	};

	static InputType recognize(std::string const &input);
	static void printArray(Values &array);
	static void fillArray(Values &array, InputType type);

public:
    static void convert(std::string const &literal);
};


#endif // SCALARCONVERTER_HPP
