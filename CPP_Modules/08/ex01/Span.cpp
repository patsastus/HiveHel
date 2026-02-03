#include "Span.hpp"

Span::Span() : data_(std::array<int,0>){    
}

Span::Span(unsigned int size) : data_(std::array<int, size>) {
}

Span::Span(const Span& other) : data_(other.data_) {
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        
    }
    return *this;
}

Span::~Span() {
}



void Span::addIterator(){

}

void Span::addNumber(int input){
	
}


unsigned int Span::shortestSpan(){

}

unsigned int Span::longestSpan(){

}
