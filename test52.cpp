/*************************************************************************
	> File Name: test52.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月13日 星期六 11时55分04秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#include <string.h>

int a[1000000];

bool is_happy(int n) {
    if (n == 1) return 1;
    if (a[n]) return 0;
    a[n] = 1;
    int sum = 0;
    while (n) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return is_happy(sum);
}


int main() {
    int n;
    while (~scanf("%d", &n)) {
        memset(a, 0, sizeof(a));
        printf("%d\n", is_happy(n));
    }
}
