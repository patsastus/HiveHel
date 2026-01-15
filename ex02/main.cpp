#include <iostream>

int main(){
	std::string actualString = "HI THIS IS BRAIN";
	std::string *stringPTR = &actualString;
	std::string &stringREF = actualString;

	std::cout << "Memory addresses:\nString: " << actualString << " at memory address " << &actualString <<std::endl;
	std::cout << "Pointer at address: " << &stringPTR << " points to " << stringPTR << " which contains " << *stringPTR << std::endl;
	std::cout << "Reference: " << &stringREF << " is an alias of the memory address of the original string " << stringREF << std::endl;

	//stringREF is an alias of actualString, this means that changes to REF also change actual:
	stringREF = "GOODBYE";
	std::cout << std::endl << "actualString is now : " << actualString << std::endl;

	return 0;
}
