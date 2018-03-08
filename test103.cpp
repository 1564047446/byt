/*************************************************************************
	> File Name: test103.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月31日 星期三 15时46分28秒
 ************************************************************************/

#include <stdio.h>

#define swap(a, b) {   \
    __typeof(a) t = a; \
    a = b; \
    b = t; \
}

void quick_sort_g(int *a, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = a[(l + r) >> 1];
        do {
            while (a[y] < z) --y;
            while (a[x] > z) ++x;
            if (x <= y) {
                swap(a[x], a[y]);
                ++x, --y;
            }
            /*printf("x = %d, y = %d\n", x, y);
            printf("a[x] = %d, a[y] = %d\n", a[x], a[y]);
            printf("z = %d\n", z);*/
        } while (x <= y);
        quick_sort_g(a, x, r);
        r = y;
    }
    return ;
}

int main() {
    int n;
    while (~scanf("%d", &n)) {
        int a[100];
        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }
        quick_sort_g(a, 0, n - 1);
        for (int i = 0; i < n; i++) printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}
