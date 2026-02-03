#include <iostream>
#include <vector>
#include <list>
#include <iterator> 
#include "easyfind.hpp"
#define COLOR_GREEN "\033[32m"
#define COLOR_RESET "\033[0m" 

int main(){
	std::list<int> intList = {1, 2, 3, 4, 5, 4, 25, 4, 42};
	std::vector<int> intVector = { 6, 7, 8, 9, 10, 7, 25, 35, 7};

	{	
	std::list<int>::iterator first = easyfind(intList, 4);
	std::cout << "Result of search :" << std::endl;
	if (first != intList.end())
		std::cout << "Found "<< *first<< " at index " << std::distance(intList.begin(), first) << std::endl;
	else
		std::cout << "Result not found" << std::endl;
	}

	{	
	std::list<int>::iterator first = easyfind(intList, 7);
	std::cout << "Result of search :" << std::endl;
	if (first != intList.end())
		std::cout << "Found "<< *first<< " at index " << std::distance(intList.begin(), first) << std::endl;
	else
		std::cout << "Result not found" << std::endl;
	}

	{	
	std::vector<int>::iterator first = easyfind(intVector, 7);
	std::cout << "Result of search :" << std::endl;
	if (first != intVector.end())
		std::cout << "Found "<< *first<< " at index " << std::distance(intVector.begin(), first) << std::endl;
	else
		std::cout << "Result not found" << std::endl;
	}

	{	
	std::vector<int>::iterator first = easyfind(intVector, 4);
	std::cout << "Result of search :" << std::endl;
	if (first != intVector.end())
		std::cout << "Found "<< *first<< " at index " << std::distance(intVector.begin(), first) << std::endl;
	else
		std::cout << "Result not found" << std::endl;
	}


}
