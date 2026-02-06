#ifndef SPAN_HPP
#define SPAN_HPP
#include <iterator>
#include <algorithm>
#include <vector>
#include <limits>

class Span {
	Span();
	std::vector<int> data_;
	unsigned int N_;
	
public:
  	Span(unsigned int size);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

	void addNumber(int input);	
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	template <typename Iterator>
	void addNumbers(Iterator begin, Iterator end){
		while (begin != end) {
			addNumber(*begin);
			++begin;
		}
	}

};

#endif // SPAN_HPP
