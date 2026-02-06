#include "Span.hpp"

Span::Span() : N_(0){
}

Span::Span(unsigned int size) : N_(size) {
	data_.reserve(size);
}

Span::Span(const Span& other) : data_(other.data_), N_(other.N_) {
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        data_ = other.data_;
		N_ = other.N_;
    }
    return *this;
}

Span::~Span() {
}

void Span::addNumber(int input){
	if (data_.size() == N_)
		throw std::exception();
	data_.push_back(input);
}


unsigned int Span::shortestSpan() const{
	if (data_.size() < 2)
		throw std::exception();
	unsigned int min = std::numeric_limits<unsigned int>::max();
	std::vector<int> copy = data_;
	std::sort(copy.begin(), copy.end());
	for (size_t i = 1; i < copy.size(); ++i){
		unsigned int test = static_cast<unsigned int>(copy[i]) - static_cast<unsigned int>(copy[i - 1]);
		min = (test < min) ? test : min;
	}
	return min;
}

unsigned int Span::longestSpan() const{
	if (data_.size() < 2)
		throw std::exception();
	std::vector<int>::const_iterator min = std::min_element(data_.begin(), data_.end());
	std::vector<int>::const_iterator max = std::max_element(data_.begin(), data_.end());
	return static_cast<unsigned int>(*max) - static_cast<unsigned int>(*min);
}


