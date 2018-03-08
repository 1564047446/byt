/*************************************************************************
	> File Name: test85.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月25日 星期四 11时53分47秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;


struct dead {
    int f, a;
    int id;
}p[50005];

bool judge(dead a, dead b) {
    return a.f <= b.f;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int num = 0, k = n - 1;
        for (int i = 0; i < n; i++) {
            int f, a;
            scanf("%d%d", &f, &a);
            p[i].f = f, p[i].a = a, p[i].id = i + 1;
        }
        sort(p, p + k + 1, judge);
        /*for (int i = 0; i < n; i++) {
            printf("%d ", p[i].f);
        }*/
        int maxn = 0, index = 0;
        for (int i = 0; i < n; i++) {
            int j = index = k;
            int flag = 0;
            for (; j >= 0; j--) {
                //index = j;
                //printf("flag = %d", flag);
                if (k == 0) {
                    printf("%d\n", p[k].id);
                    break;
                }
                if (j - 1 >= 0 && p[index].f == p[j - 1].f) {
                    if (p[index].id < p[j - 1].id) {
                        index = j - 1;
                        flag = 1;
                        printf("lalalalal\n");
                    } /*else {
                        continue;
                    }*/
                }
                printf("flag = %d", flag);
                if ((flag && j - 1 == 0)|| (flag && p[index].f != p[j - 1].f)) {
                    printf("id = %d ", p[index].id);
                    p[index].f = -1, p[index].a = -1;
                    --k;
                    break;
                }
                if (j - 1 >= 0 && p[index].f > p[j - 1].f) {
                    printf("%d ", p[index].id);
                    p[index].f = -1, p[index].a = -1;
                    --k;
                    break;
                }
            }
            for (int q = 0; q <= k; q++) {
                p[q].f += p[q].a;
                //printf("sum = %d\n", p[q].f);
            }
            sort(p, p + k + 1, judge);
            //printf("%d\n", p[0].f);
            printf("k = %d\n", k);
        }
    }
    return 0;
}
