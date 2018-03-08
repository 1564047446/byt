/*************************************************************************
	> File Name: test80.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月24日 星期三 14时37分21秒
 ************************************************************************/

#include <stdio.h>

int binary_search(int *a, int x) {
    int tail = x, head = 1, mid;
    while (tail >= head) {
        mid = (tail + head) >> 1;
        if (a[mid] == x) {
            return mid;
        } else if (a[mid] > x) {
            tail = mid - 1;
        } else if (a[mid] < x) {
            head = mid + 1;
        }
    }
    return 0;
}


int main() {
    int a[1005] = {0};
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    int x;
    scanf("%d", &x);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    for (int i = 1; i <= n; i++) {
        int result = binary_search(a, x - a[i]);
        printf("result = %d\n", result);
        if (result != 0) {
            if (i > result) {
                int t = i;
                i = result;
                result = i;
            }
            printf("%d %d\n", i, result);
            break;
        } 
    }
    return 0;
}
