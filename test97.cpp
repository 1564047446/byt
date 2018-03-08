/*************************************************************************
	> File Name: test97.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月30日 星期二 14时30分47秒
 ************************************************************************/

#include<iostream>
using namespace std;


int main() {
    int a = 3, b = 5;
    int c = a ^ b;
    int d = (a & b) << 1;
    while (d != 0) {
        a = c;
        b = d;
        c = a ^ b;
        d = (a & b) << 1;
    }
    cout << c << endl;
}
