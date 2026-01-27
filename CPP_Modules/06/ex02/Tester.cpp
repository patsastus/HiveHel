#include "Tester.hpp"

Tester::Tester() : randomGenerator(std::random_device) { 
}

Tester::Tester(const Tester& other) {
    *this = other;
}

Tester& Tester::operator=(const Tester& other) {
    if (this != &other) {
        
    }
    return *this;
}

Tester::~Tester() {
    
}

Base* Tester::generate(void){
	std::uniform_int_distribution<> rand(0,2);
	switch (rand(randomGenerator_)) {
	case 0:
		return dynamic_cast<Base*> new A();
	case 1:
		return dynamic_cast<Base*> new B();
	case 2:
		return dynamic_cast<Base*> new C();
	}
}

void Tester::identify(Base* p){

}

void Tester::identify(Base& p){

}


