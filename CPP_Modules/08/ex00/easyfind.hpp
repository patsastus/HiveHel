#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>
#include <concepts> // Required for concepts (the thing after 'requires')
#include <ranges>   // Required for std::ranges::range

template <typename T>                                            // Define a 'concept' that T can fulfill called IntContainer
concept IntContainer = std::ranges::range<T> && 				 // T must be iterable over (containers)
	std::same_as<typename std::ranges::range_value_t<T>, int>;   // must be able to hold ints

template <typename T> requires IntContainer<T>      //require that T fulfills the concept to try instantiating this function
typename T::iterator easyfind(T& container, int i) {
	return std::find(container.begin(), container.end(), i);
};

#endif // EASYFIND_HPP
