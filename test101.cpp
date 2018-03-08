/*************************************************************************
	> File Name: test101.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月31日 星期三 15时09分12秒
 ************************************************************************/

#include <stdio.h>


void merge_sort(int *a, int l, int r) {
    if (l == r) return ;
    int mid = (l + r) >> 1;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    int temp[r - l + 1];
    int index1 = l, index2 = mid + 1 , k = 0;
    while (index1 <= mid || index2 <= r) {
        if (index2 > r || (index1 <= mid && a[index1] <= a[index2])) {
            temp[k++] = a[index1++];
        } else {
            temp[k++] = a[index2++];
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
        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }
        merge_sort(a, 0, n - 1);
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}
