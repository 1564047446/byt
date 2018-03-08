/*************************************************************************
	> File Name: test43.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月02日 星期二 13时44分35秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#define inf 0xffffffff

using namespace std;

int maxn(int num, ...) {
    va_list arg;
    va_start(arg, num);
    int ans = 0;
    while (num--) {
        int t = va_arg(arg, int);
        ans = t > ans ? t : ans;
    }
    return ans;
}


int main() {
    int a = inf, b = inf, c = inf;
    int *pa = (int *)(&a);
    char *pb = (char *)(&b);
    double *pc = (double *)(&c);
    *pa = 2;
    *pb = 15;
    *pc = 16;
    /*printf("%p %p %x\n", pa, pa + 1, a);
    printf("%p %p %x\n", pb, pb + 1, b);
    printf("%p %p %x\n", pc, pc + 1, c);*/
    int n;
    printf("%d\n", maxn(3, 1, 2, 3));
    printf("%d\n", maxn(5, 1, 3, 4, 2, 1));
}
