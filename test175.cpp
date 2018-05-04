#include <iostream>

using namespace std;

template<typename T>

T add(T a, T b) {
	return a + b;
}

template<typename U, typename ...ARGS>

void print(const U &a, ARGS... args) {
	cout << a << endl;
	print(args...);
}

int main() {
	int a = 1, b = 2;
	cout << add(a, b) << endl;
	string p = "hello", q = "world";
	cout << add(p, q) << endl;
	print(2, a, b);
	return 0;
}