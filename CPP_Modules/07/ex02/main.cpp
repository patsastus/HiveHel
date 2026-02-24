#include <iostream>
#include "Array.hpp"
#define COLOR_GREEN "\033[32m"
#define COLOR_RESET "\033[0m"


int main(){
	Array<int> emptyArray;

	Array<double> *initArray = new Array<double>(4);
	for (size_t i = 0; i < initArray->size(); ++i){
		(*initArray)[i] = static_cast<double>(i * 42);
	}

	Array<double> copiedArray = *initArray;

	Array<double> *assignedArray = new Array<double>(6);
	*assignedArray = *initArray;

	for (size_t i = 0; i < copiedArray.size(); ++i){
		copiedArray[i] = copiedArray[i] - 1.0;
	}

	for (size_t i = 0; i < assignedArray->size(); ++i){
		(*assignedArray)[i] = (*assignedArray)[i] + 1.0;
	}

	std::cout << COLOR_GREEN << "Original Array:" << COLOR_RESET << std::endl;
	for (size_t i = 0; i < initArray->size(); ++i){
		std::cout << (*initArray)[i] << " ";
	}
	std::cout << "" << std::endl;

	std::cout << COLOR_GREEN << "Copied and edited Array:" << COLOR_RESET << std::endl;
	for (size_t i = 0; i < copiedArray.size(); ++i){
		std::cout << copiedArray[i] << " ";
	}
	std::cout << "" << std::endl;

	std::cout << COLOR_GREEN << "Copy-assigned and edited Array:" << COLOR_RESET << std::endl;
	for (size_t i = 0; i < assignedArray->size(); ++i){
		std::cout << (*assignedArray)[i]  << " ";
	}
	std::cout << "" << std::endl;

	try {
		int test = emptyArray[1];
		std::cout << "Out of bounds read returned " << test << std::endl;
	} catch (std::exception &e) {
		std::cout << "Caught exception trying to access element out of bounds" << std::endl;
	}

	delete assignedArray;
	delete initArray;
}
