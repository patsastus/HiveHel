#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	 return *this;
}

ScalarConverter::~ScalarConverter() { 
}


ScalarConverter::InputType ScalarConverter::recognize(std::string const &input) {
	if (input.length() == 0) {
		return Error;
	}
	else if (input.length() == 3 && input.front() == '\'' && input.back() == '\''){
		return Char;
	}
	else if (input.length() == 1 && !std::isdigit(input.front())){
		return Char;
	}
	else if (input.find('.') == std::string::npos && std::isdigit(input.back())) {
	   return Int;
	} 	   
	else if (input.back() == 'f' && 
				( (input.length() >= 2 && std::isdigit(input.at(input.size() - 2))) 
				|| input.find("inff") != std::string::npos 
				|| input.find("nanf") != std::string::npos )
			) {
		return Float;
	}
	else if (std::isdigit(input.back()) 
			|| input.find("nan") != std::string::npos
			|| input.find("inf") != std::string::npos )
	{
		return Double;
	}
	return Error;
}	

/*
 * Fills out the referenced array with values based on input and type, when 
 * possible, and sets the values in array whether conversions were possible
*/
void ScalarConverter::fillArray(Values &array, InputType type){
	if (!array.possible[type]) {
		array.possible[Char] = false;
		array.possible[Int] = false;
		array.possible[Float] = false;
		array.possible[Double] = false;
		return;
	}

	switch (type) {
		case Char:
			array.i = static_cast<int>(array.c);
			array.f = static_cast<float>(array.c);
			array.d = static_cast<double>(array.c);
			array.possible[Int] = true;
			array.possible[Float] = true;
			array.possible[Double] = true;
			break;

		case Int:
			if (array.i >= -128 && array.i <= 127) {
				array.c = static_cast<char>(array.i);
				array.possible[Char] = true;
			} else {
				array.possible[Char] = false;
			}
			array.f = static_cast<float>(array.i);
			array.d = static_cast<double>(array.i);
			array.possible[Float] = true;
			array.possible[Double] = true;
			break;

		case Float:
			if (array.f >= -128.0f && array.f <= 127.0f) {
				array.c = static_cast<char>(array.f);
				array.possible[Char] = true;
			} else {
				array.possible[Char] = false;
			}
			//need to cast the limit to double instead of float to not loose 
			//precision and cause an overflow in the static cast
			if (array.f >= double(std::numeric_limits<int>::min()) 
					&& array.f <= double(std::numeric_limits<int>::max())) {
				array.i = static_cast<int>(array.f);
				array.possible[Int] = true;
			} else {
				array.possible[Int] = false;
			}
			array.d = static_cast<double>(array.f);
			array.possible[Double] = true;
			break;
	
		case Double:
			if (array.d >= -128.0 && array.d <= 127.0) {
				array.c = static_cast<char>(array.d);
				array.possible[Char] = true;
			} else {
				array.possible[Char] = false;
			}
			if (array.d >= double(std::numeric_limits<int>::min()) 
					&& array.d <=  double(std::numeric_limits<int>::max())) {
				array.i = static_cast<int>(array.d);
				array.possible[Int] = true;
			} else {
				array.possible[Int] = false;
			}
			array.f = static_cast<float>(array.d);
			array.possible[Float] = true;
			break;

		default:
			break;
	}
}

void ScalarConverter::printArray(Values &array, InputType type) {
	if (type == Char)
		std::cout << COLOR_RED;
	std::cout << "char: ";
	std::cout << COLOR_RESET;
	if (array.possible[Char] && std::isprint(array.c)){
		std::cout << "'" << array.c << "'" << std::endl;
	} else if (array.possible[Char]) {
		std::cout << "Non displayable" << std::endl;
	} else {
		std::cout << "impossible" << std::endl;
	}

	if (type == Int)
		std::cout << COLOR_RED;
	std::cout << "int: ";
	std::cout << COLOR_RESET;
	if (array.possible[Int]){
		std::cout << array.i << std::endl;
	} else {
		std::cout << "impossible" << std::endl;
	}

	if (type == Float)
		std::cout << COLOR_RED;
	std::cout << "float: ";
	std::cout << COLOR_RESET;
	if (array.possible[Float]){
		std::cout << std::showpoint << array.f << "f" << std::noshowpoint << std::endl;
	} else {
		std::cout << "impossible" << std::endl;
	}

	if (type == Double)
		std::cout << COLOR_RED;
	std::cout << "double: ";
	std::cout << COLOR_RESET;
	if (array.possible[Double]){
		std::cout << std::showpoint << array.d<< std::noshowpoint << std::endl;
	} else {
		std::cout << "impossible" << std::endl;
	}
}

void ScalarConverter::convert(std::string const &literal){
	Values array;
	InputType which = recognize(literal);
	switch (which) {
		case Char:
			if (literal.length() == 3)
				array.c = literal[1];
			else
				array.c = literal[0];
			array.possible[Char] = true;
			break;

		case Int:
			try {
				array.i = std::stoi(literal);
				array.possible[Int] = true;
			} catch (std::invalid_argument e) {
				array.possible[Int] = false;
			} catch (std::out_of_range e) {
				array.possible[Int] = false;
			}
			break;

		case Float:
			try {
				array.f = std::stof(literal);
				array.possible[Float] = true;
			} catch (std::invalid_argument e) {
				array.possible[Float] = false;
			} catch (std::out_of_range e) {
				array.possible[Float] = false;
			}
			break;

		case Double:
			try {
				array.d = std::stod(literal);
				array.possible[Double] = true;
			} catch (std::invalid_argument e) {
				array.possible[Double] = false;
			} catch (std::out_of_range e) {
				array.possible[Double] = false;
			}
			break;

		case Error:
		default:
			std::cout << "Couldn't recognize literal" << std::endl;
	}
	if (which != Error) {
		fillArray(array, which);
		printArray(array, which);
	}
}
