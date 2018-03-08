#include <stdio.h>
#include <stdlib.h>
#define swap(a, b) { \
    __typeof(a) t = a; \
    a = b; \
    b = t; \
}

void quick_sort_good(int *num, int left, int right) {
    while (left < right){
        int x = left, y = right, z = num[(left + right) / 2];
        do {
            while (num[x] < z) ++x;
            while (num[y] > z) --y;
            if (x <= y) {
                swap(num[x], num[y]);
                ++x, --y;
            }
        } while (x <= y);
        quick_sort_good(num, x, right);
        right = y;
    }
    return ;
}

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    quick_sort_good(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        if (i == 0) printf("%d", a[i]);
        else printf(" %d", a[i]);
    }
}