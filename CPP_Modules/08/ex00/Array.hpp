#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <exception>

template <typename T> class Array {
	T *content_;
	size_t size_;

public:
	Array() : content_(new T[0]), size_(0){	};

	Array(unsigned int n): content_(new T[n]), size_(n) { };

	Array(Array const & other): content_(new T[other.size_]), size_(other.size_){
		for (unsigned int i=0; i < size_ ; ++i) {
			this->content_[i] = other.content_[i];
		}
	}

	Array & operator=(Array const & other) {
		if (this != &other) {
			T* temp = new T[other.size_];	//this could throw bad_alloc, so do it before deleting old content
			delete []this->content_;
			this->content_ = temp;
			for (unsigned int i = 0;  i < other.size_ ; ++i) {
				this->content_[i] = other.content_[i];
			}
			this->size_ = other.size_;
		}
		return *this;
	}

	~Array() {
		delete []content_;
	}

	T &operator[](size_t n) {
		if (n < size_)
			return content_[n];
		throw std::exception();
	}

	size_t size() {
		return size_;
	}
};
#endif // ARRAY_HPP
