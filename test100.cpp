/*************************************************************************
	> File Name: test100.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月31日 星期三 14时54分18秒
 ************************************************************************/

#include <stdio.h>


void merge_sort(int *a, int l, int r) {
    if (l == r) return ;
    int mid = (l + r) >> 1;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    int temp[r - l + 1];
    int x = l, y = mid + 1, k = 0;
    while (x <= mid || y <= r) {
        if (x > mid || (y <= r && a[x] >= a[y])) {
            temp[k++] = a[y++];
        } else {
            temp[k++] = a[x++];
        }
    }
    for (int i = l; i <= r; i++) {
        a[i] = temp[i - l];
    }
    return ;
}

int main() {
    int n;
    while (~scanf("%d", &n)) {
        int a[100];
        for (int i = 0; i < n ;i++) {
            scanf("%d", a + i);
        }
        merge_sort(a, 0, n - 1);
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    return 0;
}
