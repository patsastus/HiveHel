#ifndef SPAN_HPP
#define SPAN_HPP

#include <array>

class Span {
	Span();
	std::array<int> data_;

public:
  	Span(unsigned int size);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

	void addNumber(int input);	
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
};

#endif // SPAN_HPP
