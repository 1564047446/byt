/*************************************************************************
	> File Name: test128.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月05日 星期一 17时47分11秒
 ************************************************************************/

#include <stdio.h>

int is_prime(int x)  {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

void get_double(int x) {
    int a[100];
    int cnt = 0;
    while (x) {
        //printf("%d", x % 2);
        int k = x % 2;
        a[cnt++] = k;
        x /= 2;
        //printf("%d", x % 2);
    }
    for (int i = cnt - 1; i >= 0; i--) {
        printf("%d", a[i]);
    }
    printf("\n");
    return ;
}


int main() {
    int x;
    while (~scanf("%d", &x)) {
        printf("%d\n", is_prime(x));
        printf("double num is : ");
        get_double(x);
    }
    return 0;
}
