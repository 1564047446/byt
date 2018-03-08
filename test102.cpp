/*************************************************************************
	> File Name: test102.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月31日 星期三 15时14分45秒
 ************************************************************************/

#include <stdio.h>

#define swap(a, b) {  \
    __typeof(a) t = a; \
    a = b; \
    b = t; \
}

void quick_sort(int *a, int l, int r) {
    if (l >= r) return ;
    int x = l, y = r, z = a[l];
    while (x < y) {
        while (x < y && a[y] > z) --y;
        if (x < y) {
            swap(a[x], a[y]);
        }
        while (x < y && a[x] < z) ++x;
        if (x < y) {
            swap(a[x], a[y]);
        }
    }
    a[x] = z;
    quick_sort(a, l, x);
    quick_sort(a, x + 1, r);
}

int main() {
    int n;
    while (~scanf("%d", &n)) {
        int a[100];
        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }
        quick_sort(a, 0, n - 1);
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    return 0;
}
