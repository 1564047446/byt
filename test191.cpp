/*************************************************************************
	> File Name: test191.cpp
	> Author:  byt 
	> Mail: baotongyu1995@163.com
	> Created Time: 2018年06月01日 星期五 13时29分06秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstdio>
#include <functional>

using namespace std;	

auto f = [](auto x) {
	return x;
};

int add(int x) {
	return x;
}

auto g = [](auto x, auto y) {
	return x + y;
};

int main() {
	int a = 10;
	auto b = a;
	cout << b << endl;
	cout << f(4) << endl;
	cout << g(f(4), 3) << endl;
	return 0;
}