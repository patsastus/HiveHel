#ifndef DATA_HPP
#define DATA_HPP
#include <iostream>

struct Data {
    Data();
    Data(const Data& other);
    Data& operator=(const Data& other);
    ~Data();

	int			id;
	std::string	input;
	double		value;
};

std::ostream & operator<<(std::ostream &os, Data const &d );
#endif // DATA_HPP
