#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T> void swap(T &a, T &b) {
	T temp = b;
	b = a;
	a = temp;
}

//returning a value was asked, rather than a reference
template <typename T> T min(T a, T b) {
	return (a < b) ? a : b;
}

//returning a value was asked, rather than a reference
template <typename T> T max(T a, T b) {
	return (a > b) ? a : b;
}


#endif // WHATEVER_HPP
