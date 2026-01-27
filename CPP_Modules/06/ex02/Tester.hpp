#ifndef TESTER_HPP
#define TESTER_HPP
#include "Base.hpp"
#include <iostream>

class Tester {
public:
    Tester();
    Tester(const Tester& other);
    Tester& operator=(const Tester& other);
    ~Tester();

	Base *generate(void);
	void identify(Base* p);
	void identify(Base& p);

private:
	std::mt19937 randomGenerator_;
};

#endif // TESTER_HPP
