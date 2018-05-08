/*************************************************************************
	> File Name: test178.cpp
	> Author:  muhuilin 
	> Mail: 
	> Created Time: 2018年05月07日 星期一 13时15分07秒
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;


int main() {
    string a = "abcde";
    string b(begin(a) + 2, begin(a) + 5);
    cout << b << endl;
    a.replace(begin(a) + 2, begin(a) + 5, "aaaa");
    cout << a << endl;
    auto x = a.find("aaa");
    cout << "x = " << x << endl;
    auto y = a.find("ddd");
    cout << "y = " << y << endl;
    return 0;
}
