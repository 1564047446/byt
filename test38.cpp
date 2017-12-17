/*************************************************************************
	> File Name: test38.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月15日 星期五 14时32分18秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;

#define inf 1e-7

int (*func)(int x);

#define max(a, b) ({ \
    __typeof(a)temp1 = (a); \
    __typeof(b)temp2 = (b); \
    temp1 > temp2 ? temp1 : temp2;\
})

int power(int x) {
    return x * x;
}

int get_power(int x) {
    func = power;
    
    printf("kakaka %d\n", (*func)(x));
}


double newton(double n) {
    double x = 1.0;
    func = power;
    while (fabs(x * x - n) > inf) {
        x = x - (x * x - n) / (2 * x);
    }
    return x;
}



int main() {
    int a, b;
    double n;
    while (scanf("%lf", &n)) {
        //printf("max = %d\n", max(a, b));
        printf("%lf\n", newton(n));
    }
}
