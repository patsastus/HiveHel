#include "Brain.hpp"

Brain::Brain() : thoughtIndex_(0){
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other) : thoughtIndex_(other.thoughtIndex_){
    for (size_t i = 0; i < other.thoughtIndex_; ++i){
		ideas_[i] = other.ideas_[i];
	}
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
		int index = other.thoughtIndex_;
		if (index > 100)
			index = 100;
		for (int i = 0; i < index; ++i) {
			this->ideas_[i] = other.ideas_[i];
	   }
	   this->thoughtIndex_ = other.thoughtIndex_;
    }
    return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called @" << this << std::endl;
}

void Brain::addThought(const std::string &t){
	if (thoughtIndex_ >= 100)
		ideas_[thoughtIndex_%100] = t;
	else
		ideas_[thoughtIndex_] = t;
	++thoughtIndex_;
}

std::string Brain::recallThought(size_t index) const{
	if (index >= thoughtIndex_)
		return "|empty|";
	if (index >= 100)
		return ideas_[index%100];
	return ideas_[index];
}

void Brain::dump() const{
	std::cout << recallThought(0) << std::endl;
	for (size_t i = 1; i <= thoughtIndex_ ; ++i) {
		std::cout << recallThought(i) << std::endl;
	}
}

