#ifndef ITER_HPP
#define ITER_HPP
#include <cstddef>

//this automatically checks that constness of 'function' doesn't downgrade constness of 'array'
//also allows for function with a return type, even though we discard it.
template <typename T, typename F> void iter(T *array, size_t const length, F function){
	for (size_t i = 0; i < length; i++){
		function(array[i]);
	}
}



#endif // ITER_HPP
