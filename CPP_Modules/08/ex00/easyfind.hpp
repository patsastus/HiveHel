#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>
#include <concepts> // Required for concepts (the thing after 'requires'
#include <ranges>   // Required for std::ranges::range
					
template <typename T> 
requires std::ranges::range<T> && 				// T must be iterable (ie a container)
	std::same_as<typename T::value_type, int> // must be able to hold ints
typename T::iterator easyfind(T& container, int i) {
	return std::find(container.begin(), container.end(), i);
};

#endif // EASYFIND_HPP
