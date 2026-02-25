#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include "MutantStack.hpp"
#define COLOR_GREEN "\033[32m"
#define COLOR_RESET "\033[0m"

int main(){
	{
		MutantStack<int> mstack;
		MutantStack<int, std::vector<int> > vectorStack;
		std::list<int> notAStack;
		std::list<int> inputs = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, -50};

		std::list<int>::iterator start = inputs.begin(), end = inputs.end();
		while (start != end ){
			mstack.push(*start);
			vectorStack.push(*start);
			notAStack.push_back(*start);
			++start;
		}

		std::stack<int> s(mstack); 					//checking that it can be copied to a standard stack;
		MutantStack<int> copy;
	   	copy = mstack;								//copy assignment
		const MutantStack<int> constCopy(mstack);	//copy constructor & const-ness

		std::cout << COLOR_GREEN << "Top element: "<< COLOR_RESET << mstack.top();
		std::cout<< COLOR_GREEN << " (expected "<< inputs.back() <<")" << std::endl;

		mstack.pop();
		notAStack.pop_back();
		vectorStack.pop();

		{
			std::cout << COLOR_GREEN << "Iterating over the MutantStack" << COLOR_RESET << std::endl;
			MutantStack<int>::iterator it = mstack.begin(), ite = mstack.end();
			++it;
			--it;
			while (it != ite)
			{
				std::cout << *it << " ";
				++it;
			}
			std::cout << std::endl;
		}
		{
			std::cout << COLOR_GREEN << "Iterating over the MutantStack with a vector as the container" << COLOR_RESET << std::endl;
			MutantStack<int, std::vector<int> >::iterator it = vectorStack.begin(), ite = vectorStack.end();
			++it;
			--it;
			while (it != ite)
			{
				std::cout << *it << " ";
				++it;
			}
			std::cout << std::endl;
		}

		{
			std::cout << COLOR_GREEN << "Iterating over the identical list" << COLOR_RESET << std::endl;
			std::list<int>::iterator it = notAStack.begin(), ite = notAStack.end();
			++it;
			--it;
			while (it != ite)
			{
				std::cout << *it << " ";
				++it;
			}
		}

		{
			std::cout << std::endl << COLOR_GREEN << "Reverse iterating over a copy of the MutantStack" << COLOR_RESET << std::endl;
			MutantStack<int>::reverse_iterator it = copy.rbegin();
			MutantStack<int>::reverse_iterator ite = copy.rend();
			while (it != ite)
			{
				std::cout << *it << std::endl;
				++it;
			}
		}
		{
			std::cout << std::endl << COLOR_GREEN << "Iterating both ways over a const copy of the MutantStack" << COLOR_RESET << std::endl;
			MutantStack<int>::const_reverse_iterator rit = constCopy.rbegin();
			MutantStack<int>::const_reverse_iterator rite = constCopy.rend();
			MutantStack<int>::const_iterator it = constCopy.begin();
			MutantStack<int>::const_iterator ite = constCopy.end();
			while (it != ite && rit != rite)
			{
				std::cout << *it << "\t" << *rit << std::endl;
				++it;
				++rit;
			}

		}
	}
	return 0;
}
