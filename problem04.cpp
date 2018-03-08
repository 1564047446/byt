/*************************************************************************
	> File Name: problem04.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月22日 星期五 16时03分41秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <math.h>


using namespace std;


int is_value(int x) {
    int digit = floor(log10(x));
    while (x) {
        int k = pow(10, digit);
        int n1 = x / k;
        int n2 = x % 10;
        //printf("%d  %d %d\n", n1, n2, x);
        if (n1 != n2) return 0;
        x %= k;
        x /= 10;
        digit -= 2;
    }
    return 1;
}



int is_value2(int x) {
    int x1 = x;
    int sum = 0;
    while (x) {
        sum = sum * 10 + x % 10;
        x /= 10;
    }
    if (sum == x1) return 1;
    else return 0;
}


int main () {
    for (int i = 100; i <= 999; i++) {
        for (int j = 100; j <= 999; j++) {
            if (is_value(i * j)) {
                printf("%d * %d = %d\n", i, j, i * j);
            }
        }
    }
    /*int n;
    while (~scanf("%d", &n)){
        is_value(n);
    }*/
}
