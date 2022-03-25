#include "iter.hpp"

template <typename T>
void print_arr(T a) {
	std::cout << a << " ";
}

template <typename T>
void increment_arr(T &a) {
	a++;
}

int main() {
	int arr1[] = {1, 2, 3, 4, 5};
	std::string arr2[] = {"one", "two", "three", "four", "five"};
	float arr3[] = {1.2f, 2.23f, 3.312f, 4.45f, 5.1f};
	::iter(arr1, 5, increment_arr);
	::iter(arr1, 5, print_arr);
	std::cout << std::endl;
	::iter(arr2, 5, print_arr);
	std::cout << std::endl;
	::iter(arr3, 5, increment_arr);
	::iter(arr3, 5, print_arr);
	std::cout << std::endl;
	return 0;
}