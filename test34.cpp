/*************************************************************************
	> File Name: test34.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月09日 星期六 21时14分44秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
using namespace std;

 

int is_prime(int n) {
    int prime[10001] = {0}; 
    for (int i = 2; i < 10001; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > 10001) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return prime[n];
}


int main() {
    int num = 0;
    for (int i = 2; i < 100; i++) {
        int flag = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) 
        printf("%d     %d\n", is_prime(++num), i);
    }
}
