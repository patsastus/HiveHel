#include <iostream>
#include "iter.hpp"
#define COLOR_GREEN "\033[32m"
#define COLOR_RESET "\033[0m" 

void addOne(int &input){
	std::cout << ++input <<std::endl;
};

void addOneConst(int const& input){
	std::cout << (input+1) <<std::endl;
};


int main(){
	int array[] = {1,2,3,42};
	int const constArray[] = {1,2,3,24};

	std::cout << COLOR_GREEN << "non-const version :" << COLOR_RESET << std::endl;
	iter(array, 4, &addOne);

	std::cout << std::endl << COLOR_GREEN << "non-const version, run a second time:" << COLOR_RESET << std::endl;
	iter(array, 4, &addOne);

	std::cout << COLOR_GREEN << "const version :" << COLOR_RESET << std::endl;
	iter(constArray, 4, &addOneConst);

	std::cout << std::endl << COLOR_GREEN << "const version, run a second time:" << COLOR_RESET << std::endl;
	iter(constArray, 4, &addOneConst);

}
