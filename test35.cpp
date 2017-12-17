/*************************************************************************
	> File Name: test35.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月10日 星期日 23时51分34秒
 ************************************************************************/

#include <stdio.h>


int gcd(int a, int b) {
    if (b == 0) return a;
    printf("a = %d    b = %d\n", a, b);
    return gcd(b, a % b);
}


int main() {
    int a, b;
    while (~scanf("%d%d", &a, &b)) {
        printf("%d\n", gcd(a, b));
    }
}
