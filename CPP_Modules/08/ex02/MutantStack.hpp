#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
    //enforce typing for early/better error messages
    static_assert(std::same_as<typename Container::value_type, T>, "Container::value_type must match T");
    //defining some shorter names
	typedef std::stack<T, Container> StackType;
	typedef typename StackType::container_type::iterator iterator;
	typedef typename StackType::container_type::const_iterator const_iterator;
	typedef typename StackType::container_type::reverse_iterator reverse_iterator;
	typedef typename StackType::container_type::const_reverse_iterator const_reverse_iterator;

    MutantStack() : StackType() {};
    MutantStack(const MutantStack& other): StackType(other) {};
    MutantStack& operator=(const MutantStack& other) {
		if (this != &other) {
			this->StackType::operator=(other) ;
		}
		return *this;
	};
    virtual ~MutantStack(){};

	//all iterators just expose the iterators of the underlying container
	iterator begin(){ return this->c.begin(); }

	const_iterator begin() const{ return this->c.begin(); }

	reverse_iterator rbegin(){ return this->c.rbegin();	}

	const_reverse_iterator rbegin() const{ return this->c.rbegin();	}

	iterator end(){ return this->c.end(); }

	const_iterator end() const{	return this->c.end(); }

	reverse_iterator rend(){ return this->c.rend(); }

	const_reverse_iterator rend() const{ return this->c.rend();	}
};

#endif // MUTANTSTACK_HPP
