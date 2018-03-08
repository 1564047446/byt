/*************************************************************************
	> File Name: test96.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月27日 星期六 19时49分32秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>

#define inf 1e-5

double get_ans(int a, int b, int c) {
    double l = 0, r = 20;
    a = (double)a, b = (double)b, c = (double)c;
    double x1 = (l + r) / 3, x2 = (l + r) / 3 * 2;
    while (fabs(x1 - x2) > inf) {
        if (fabs(x1 - x2) == inf) return x1 - x2;
        if (x1 * x1 * a + b * x1 < x2 * x2 * a + b * x2) {
            l = x1;
        } else {
            r = x2;
        }
        x1 = (l + r) / 3, x2 = (l + r) / 3 * 2;
    }
    return 0.0;
}


int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("ans = %lf\n", get_ans(a, b, c));
}
