#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>


class ScalarConverter {
//private constructors make the class uninstantiable.
private: 
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();
public:
    static void convert(std::string const &literal);
};

#endif // SCALARCONVERTER_HPP
