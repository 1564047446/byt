/*************************************************************************
	> File Name: test99.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月31日 星期三 08时12分48秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_sort(int *num, int n) {
    #define maxn_x 65535
    int *cnt = (int *)calloc(maxn_x + 1, sizeof(int));
    int *temp = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        cnt[(num[i] & 65355) + 1] += 1;
    }
    for (int i = 1; i <= maxn_x; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < n; i++) {
        temp[cnt[num[i] & 65535] ++] = num[i];
    }
    int *p = num;
    num = temp;
    temp = p;
    memset(cnt, 0, sizeof(int) * (maxn_x + 1));
    for (int i = 0; i < n; i++) {
        cnt[((num[i] >> 16) & 65535) + 1]++;
    }
    for (int i = 1; i <= maxn_x; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < n; i++) {
        temp[(cnt[(num[i] >> 16) & 65535]) ++] = num[i];
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
    get_sort(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
