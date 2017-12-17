/*************************************************************************
	> File Name: test32.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月08日 星期五 19时24分19秒
 ************************************************************************/

#include <stdio.h>

#define 1e-7
#define magic_num 0x5f375a86
#define magic_num2 0x5f3759df

double fabs(double x) {
    return x > 0 ? x : -x;
}

double sqrt1(double x) {
    double head = 0, tail = x + 0.5,  mid = (head + tail) >> 1;
    while(tail - head > epslon) {
        if(fabs(mid * mid - x) < epslon) return mid;
        if(mid * mid > x) tail = mid;
        if(mid * mid < x) head = mid;
        mid = (head + tail) >> 1;
    }
    return head;
}


double newton_sqrt(double n) {
    if (n <= 0.0) return 0.0;
    double x = 1.0;
    int times = 0;
    while (fabs(x * x - n) > epslon) {
        x = x - (x * x - n) / (2 * x);
        times++;
    }
    printf("%d\n", times);
    return x;
}


double magic_sqrt(double n) {
    double x = magic_num;
    x = x - ()
}m
