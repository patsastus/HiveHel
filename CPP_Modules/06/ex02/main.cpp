#include <iostream>
#include "Tester.hpp"

class Base;
int main() {
	Tester tester;

	int numTests = 10;
	for (int i=0; i < numTests; ++i) {
		Base *pointer = tester.generate();
		Base &reference = *pointer;
		std::cout <<i<< ": Investigating Base object @" << pointer << ":" << std::endl;
		std::cout << "Calling identify(Base *p):" << std::endl;
		tester.identify(pointer);
		std::cout << "Calling identify(Base &p):" << std::endl;
		tester.identify(reference);
		std::cout << "" << std::endl;
		delete pointer;
	}
}
