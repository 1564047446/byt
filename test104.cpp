/*************************************************************************
	> File Name: test104.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月31日 星期三 19时02分38秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void get_sort(unsigned int *a, int n) {
    int maxn = 65535;
    int *cnt = (int *)calloc(maxn, sizeof(int));
    unsigned *temp = (unsigned int *)malloc(sizeof(unsigned int) * n);
    for (int i = 0; i < n; i++) {
        cnt[(a[i] & maxn) + 1] += 1;
    }
    for (int i = 1; i < maxn; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < n; i++) {
        temp[cnt[(a[i] & maxn)] ++] = a[i];
    }
    memset(cnt, 0, sizeof(int) * maxn);
    unsigned int *p = temp;
    temp = a;
    a = p;
    for (int i = 0; i < n; i++) {
        cnt[(a[i] >> 16 & maxn) + 1] += 1;
    }
    for (int i = 1; i < maxn; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < n; i++) {
        temp[cnt[(a[i] >> 16 & maxn)] ++] = a[i];
    }
    return ;

}

int main() {
    int n;
    while (~scanf("%d", &n)) {
        unsigned int a[100];
        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }
        get_sort(a, n);
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    return 0;
}
