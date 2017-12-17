/*************************************************************************
	> File Name: test21.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月02日 星期六 14时47分12秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
using namespace std;

#ifdef DEBUG

#define log(format, s...) ({ \
    printf("[%s : %s : %d ] ",__FILE__, __func__, __LINE__);\
    printf(format, ##s); \
    printf("\n");   \
})
#else
#define log(format, a...){}
#endif

int main() {
    char s[100] = {'0'};
    int a = 1;
    double b = 2;
    log("%d, %lf", a, b);
    printf("%lf\n", PI);
    return 0;
}
