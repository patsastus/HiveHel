#ifndef ITER_HPP
#define ITER_HPP

//funcpointer is allowed to modify array elements
template <typename T> void iter(T *array, size_t const length, void (*funcPointer)(T&)){
	for (size_t i = 0; i < length; i++){
		funcPointer(array[i]);
	}
}

//funcpointer is not allowed to modify array elements
template <typename T> void iter(T const* array, size_t const length, void (*funcPointer)(T const&)){
	for (size_t i = 0; i < length; i++){
		funcPointer(array[i]);
	}
}

//this automatically checks that constness of 'function' doesn't downgrade constness of 'array'
//also allows for function with a return type, even though we discard it.
template <typename T, typename F> void betterIter(T *array, size_t const length, F function){
	for (size_t i = 0; i < length; i++){
		function(array[i]);
	}
}



#endif // ITER_HPP
