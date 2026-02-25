#include "Span.hpp"
#include <exception>
#include <iostream>
#include <limits>
#include <vector>

// made a custom iterator for testing
class SparseIterator {
  int value_;          // current value
  int step_;           // how much value changes when iterator moves forward
  unsigned int index_; // how many times iterator has been called
  SparseIterator() = default;
  SparseIterator(SparseIterator const &other) = default;
  SparseIterator &operator=(SparseIterator const &other) = default;

  public:
  ~SparseIterator() = default;
  SparseIterator(int start, int step)
      : value_(start), step_(step),
        index_(0){}; // two ints constructor <==> set value and step
  SparseIterator(int count)
      : value_(0), step_(0),
        index_(count){}; // one int  constructor <==> set index

  int operator*() const { return value_; };
  SparseIterator &operator++() {
    if ( (step_ > 0 && std::numeric_limits<int>::max() - step_ < value_ ) ||
         (step_ < 0 && std::numeric_limits<int>::min() - step_ > value_) ) {
      throw std::exception();
    }
    value_ += step_;
    index_++;
    return *this;
  };
  // comparing iterators only cares about index, so we can use one created with
  // index as a "stop sign"
  bool operator!=(const SparseIterator &other) const {
    return index_ != other.index_;
  };
};

int main() {
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
    // using some standard iterators
    std::vector<int> inputs = {7, 3, 8, 42, 47, 999};
    Span sp = Span(inputs.size());
    sp.addNumbers(inputs.begin(), inputs.end());
    std::cout << "Shortest Span: " << sp.shortestSpan()
              << std::endl; // expected 1
    std::cout << "Longest Span:  " << sp.longestSpan()
              << std::endl; // expected 996
  }
  {
    // using a custom iterator
    int start = 42;
    int step = 11;
    int count = 50000;
    Span sp(count);
    try {
      sp.addNumbers(SparseIterator(start, step), SparseIterator(count));
    } catch (const std::exception &e) {
      std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "Shortest Span: " << sp.shortestSpan()
              << " (Expected: " << step << ")" << std::endl;

    std::cout << "Longest Span:  " << sp.longestSpan()
              << " (Expected: " << (count - 1) * step << ")" << std::endl;
  }
  {
    // testing that longestSpan still works when Span has both intMax and intMin
    int start = std::numeric_limits<int>::min();
    int step = 100;
    int count = 11000;
    Span sp(count + 1);
    try {
      sp.addNumbers(SparseIterator(start, step), SparseIterator(count));
      sp.addNumber(std::numeric_limits<int>::max());
    } catch (const std::exception &e) {
      std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "Shortest Span: " << sp.shortestSpan()
              << " (Expected: " << step << ")" << std::endl;

    std::cout << "Longest Span:  " << sp.longestSpan()
              << " (Expected: " << std::numeric_limits<unsigned int>::max()
              << ")" << std::endl;
  }

  return 0;
}
