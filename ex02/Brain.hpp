#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>
#include <iostream>

class Brain {
public:
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();
	
	void addThought(const std::string &t);
	void dump() const;

private:
	std::string ideas_[100];
	size_t		thoughtIndex_;

	std::string recallThought(size_t index) const;

};

#endif // BRAIN_HPP
