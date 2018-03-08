/*************************************************************************
	> File Name: test44.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月02日 星期二 15时08分25秒
 ************************************************************************/

#include <stdio.h>


#define my_arg(pp, T) ({ \
    T *temp2 = (T *)(pp); \
    pp = (__typeof(pp))(temp2 + 1); \
    *temp2; \
})



int main() {
    char buffer[100];
    for (int i = 0; i < 100; i++) {
        buffer[i] = i % 16;
    }
    double *p1 = (double *)(buffer + 4);
    *p1 = 123.456;
    double *p = (double *)buffer;
    int a = my_arg(p, int);
    printf("%d %x %p\n", a, a, p);
    double b = my_arg(p, double);
    printf("%lf %p\n", b, p);
    return 0;
}
