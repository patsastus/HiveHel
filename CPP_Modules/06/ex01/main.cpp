#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
	struct Data info;
	uintptr_t address = Serializer::serialize(&info);
	std::cout << "Original struct: " << info << &info << std::endl;

	std::cout << "Serialized Raw address :" << address << " @" << &address << std::endl;

	Data *restored = Serializer::deserialize(address);

	std::cout << "Restored struct address, and original address: " << std::endl << restored  << std::endl<< &info << std::endl;

	std::cout << "Accessing the struct via the serialized/desrialized pointer:" << std::endl;
	std::cout << *restored << std::endl;

}
