/*************************************************************************
	> File Name: test25.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月03日 星期日 18时51分41秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int a[1001] = {0};



int main() {
    a[0] = 1, a[1] = 2;
    int n;
    while(~scanf("%d", &n))
{
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= a[0]; j++) {
            a[j] *= 2;
        }
        for(int j = 1; j <= a[0]; j++) {
            if(a[j] < 10) continue;
            a[j + 1] += a[j] / 10;
            a[j] %= 10;
            if(j == a[0]) a[0] ++;
        }
    }
    for(int i = a[0]; i > 0; i--) {
        printf("%d", a[i]);
    }
}
}
