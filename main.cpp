#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

template <typename T, typename S>
auto func(T a, S b) -> decltype(a + b) {
	return a + b;
}

template <typename T, typename S>
auto sum_of_elements(std::vector<T> v, S start, decltype(v[0] + start) (*pf)(T, S)) -> decltype(v[0] + start) {
	decltype(v[0] + start) sum = pf(v[0], start);
	for (auto it = v.begin() + 1; it < v.end(); ++it)
		sum = pf(*it, sum);
	return sum;
}

int main() {
	int size;
	std::cout << "Enter the size of array:" << std::endl;
	std::cin >> size;
	std::vector<int> v(size);
	std::cout << "Enter elements of array:" << std::endl;
	std::for_each(v.begin(), v.end(), [](int &n){ std::cin >> n; });
	std::cout << "Sum of array's elements: " << sum_of_elements(v, 0, func) << std::endl;
	return 0;
}