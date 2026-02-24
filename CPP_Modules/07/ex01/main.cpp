#include <iostream>
#include "iter.hpp"
#define COLOR_GREEN "\033[32m"
#define COLOR_RESET "\033[0m"

template <typename T> void printOfType(T &element){
    std::cout << "Element: " << element << std::endl;
};

void addOne(int &input){
	std::cout << ++input <<std::endl;
};

void addOneConst(int const& input){
	std::cout << (input+1) <<std::endl;
};


int main(){
	int array[] = {1,2,3,42};
	int const constArray[] = {1,2,3,24};
	std::string const strArray[] = {"Hello", "World"};

	std::cout << COLOR_GREEN << "non-const version :" << COLOR_RESET << std::endl;
	iter(array, 4, &addOne);

	std::cout << std::endl << COLOR_GREEN << "non-const version, run a second time:" << COLOR_RESET << std::endl;
	iter(array, 4, &addOne);

	std::cout << std::endl << COLOR_GREEN << "const version :" << COLOR_RESET << std::endl;
	iter(constArray, 4, &addOneConst);

	std::cout << std::endl << COLOR_GREEN << "const version, run a second time:" << COLOR_RESET << std::endl;
	iter(constArray, 4, &addOneConst);

	std::cout << std::endl << COLOR_GREEN << "Templated function run on every array:" << COLOR_RESET << std::endl;
	iter(array, 4, &printOfType<int const>);  //this one compiles: you can treat a non-const int & as const if you want
	iter(constArray, 4, &printOfType<int const>);
	//iter(constArray, 4, &printOfType<int>); //this won't compile: trying to pass a const int & to something that expects int&
	iter(strArray, 2, &printOfType<std::string const>);

	std::cout << std::endl << COLOR_GREEN << "Lambda function run on string array:" << COLOR_RESET << std::endl;
	//lambda functions are anonymous, local functions, syntax: [outside vars passed in] (params) {function body} => returns a "function pointer"
	// here, let's print out at most 2 character of every string
	size_t length = 3;
	iter(strArray, 2, [length] (std::string const &s) {
	    if(length >= s.length()){
    		std::cout<< s << std::endl;
		}else {
		    std::cout << s.substr(0, length) << std::endl;
		}
	});
}
