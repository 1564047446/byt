/*************************************************************************
	> File Name: test154.cpp
	> Author:  muhuilin 
	> Mail: 
	> Created Time: 2018年04月13日 星期五 19时04分02秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
using namespace std;


int main() {
    unsigned char i = 7;
    int j = 0;
    for (; i > 0; i -= 3) {
        ++j;
    }
    cout << j << endl;
    return 0;
}
