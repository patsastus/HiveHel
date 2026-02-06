#include <iostream>
#include <vector>
#include <iterator> 
#include "Span.hpp"

//made a custom iterator for testing
class SparseIterator {
	int value_;
    int step_;
	int index_;
	SparseIterator() {};
	SparseIterator(SparseIterator const&other) {};
	SparseIterator& operator=(SparseIterator const&other) {};

public:
    // --- required to be used interchangeably with std::iterator<int>
	typedef std::input_iterator_tag iterator_category;
    typedef int						value_type;
    typedef std::ptrdiff_t			difference_type;
    typedef const int*				pointer;
    typedef const int&				reference;
    // ------------------------------------
	~SparseIterator() = default;
	SparseIterator(int start, int step) : value_(start), step_(step), index_(0) {};
    SparseIterator(int count) : value_(0), step_(0), index_(count) {};
   	int operator*() const {
		return value_;
	};
	SparseIterator& operator++() {
		value_ += step_;
		index_++;
		return *this;
	};
	bool operator!=(const SparseIterator& other) const {
		return index_ != other.index_;
	}
};

int main(){
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
	    int start = 42;
	    int step  = 11;
    	int count = 50000;
		Span sp(count);
		try {
			sp.addNumbers(SparseIterator(start, step), SparseIterator(count));
		}
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		std::cout << "Shortest Span: " << sp.shortestSpan() << " (Expected: " << step << ")" << std::endl;
		
		std::cout << "Longest Span:  " << sp.longestSpan() << " (Expected: " << (count - 1) * step << ")" << std::endl;
	}
	{
		int start = std::numeric_limits<int>::min();
	    int step  = 100;
    	int count = 11000;
		Span sp(count + 1);
		try {
			sp.addNumbers(SparseIterator(start, step), SparseIterator(count));
			sp.addNumber(std::numeric_limits<int>::max());
		}
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		std::cout << "Shortest Span: " << sp.shortestSpan() << " (Expected: " << step << ")" << std::endl;
		
		std::cout << "Longest Span:  " << sp.longestSpan() << " (Expected: " << std::numeric_limits<unsigned int>::max() << ")" << std::endl;
	}

	return 0;
}
