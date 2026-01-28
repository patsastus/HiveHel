#include "Tester.hpp"

//syntax: gives randomGenerator a seed based on a std::random_device
//compiler chooses an appropriate source of randomness available
Tester::Tester() : randomGenerator_(std::random_device{}()) { 
}

Tester::Tester(const Tester& other) {
    *this = other;
}

Tester& Tester::operator=(const Tester& other) {
	(void)other;
	return *this;
}

Tester::~Tester() {
    
}

Base* Tester::generate(void){
	std::uniform_int_distribution<> integer(0,2);
	switch (integer(randomGenerator_)) {
	case 0:
		return dynamic_cast<Base*> (new A());
	case 1:
		return dynamic_cast<Base*> (new B());
	case 2:
		return dynamic_cast<Base*> (new C());
	}
	return nullptr;
}

void Tester::identify(Base* p){
	if (A* test = dynamic_cast<A*>(p); test != nullptr) {
		std::cout << "A" << std::endl;
		return;
	} else if (B* test = dynamic_cast<B*>(p); test != nullptr) {
		std::cout << "B" << std::endl;
		return;
	} else if (C* test = dynamic_cast<C*>(p); test != nullptr) {
		std::cout << "C" << std::endl;
		return;
	}
}

void Tester::identify(Base& p){
	try {
		A& test = dynamic_cast<A&>(p);
		(void)test;
		std::cout << "A" << std::endl;
		return;
	} catch (std::bad_cast e) {	}

	try {
		B& test = dynamic_cast<B&>(p);
		(void)test;
		std::cout << "B" << std::endl;
		return;
	} catch (std::bad_cast e) {	}

	try {
		C& test = dynamic_cast<C&>(p);
		(void)test;
		std::cout << "C" << std::endl;
		return;
	} catch (std::bad_cast e) {	}
}


