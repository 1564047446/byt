/*************************************************************************
	> File Name: test107.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年02月09日 星期五 10时07分46秒
 ************************************************************************/

#include <stdio.h>

int binary_search(int *a, int value, int n) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (a[mid] != value) {
            head = mid + 1;
        } else if (a[mid] == value) {
            tail = mid;
        }
        printf("mid = %d\n", mid);
    }
    return head;
}

int main() {
    int a[100];
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }
        printf("ans = %d\n", binary_search(a, 1, n));
    }
}
