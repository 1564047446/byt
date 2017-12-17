/*************************************************************************
	> File Name: haizeijob-2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月04日 星期一 12时47分55秒
 ************************************************************************/

#include <stdio.h>

int a[1001] = {0};

int main() {
    a[0] = 1, a[1] = 1;
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= a[0]; j++) {
                a[j] *= 2;
            }
            for(int j = 1; j <= a[0]; j++) {
                if(a[j] < 10) continue;
                a[j + 1] += a[j] / 10;
                a[j] %= 10;
                if(j == a[0]) a[0]++;
            }
        }
        for(int i = a[0]; i > 0; i--) {
            printf("%d", a[i]);
        }
    }
}
