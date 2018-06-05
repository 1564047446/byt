/*************************************************************************
	> File Name: test192.cpp
	> Author:  byt 
	> Mail: baotongyu1995@163.com
	> Created Time: 2018年06月01日 星期五 20时00分25秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

bool prime[10000] = {0};

int main() {
    for (int i = 2; i < 1000; i++) {
        if (!prime[i]) {
            prime[i] = 1;
        }
        for (int j = 1; ; j++) {
            prime[i * prime[j]]
        }
    }
}
