#include "Data.hpp"

Data::Data() : id(0), input("Have a nice day"), value(42.0){
}

Data::Data(const Data& other) {
    *this = other;
}

Data& Data::operator=(const Data& other) {
    if (this != &other) {
        id = other.id;
		input = other.input;
		value = other.value;
    }
    return *this;
}

Data::~Data() { 
}

std::ostream & operator<<(std::ostream &os, Data const &d ){
	os << "Struct: " << d.id << ", '" << d.input << "', ";
   	os << d.value << std::endl;
	return os;
}
