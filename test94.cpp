/*************************************************************************
	> File Name: test94.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月26日 星期五 16时31分05秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) { \
    __typeof(a) __t = a;\
    a = b;\
    b = __t;\
}

typedef struct Heap {
    int *pi, *di;
    int n, size;
} Heap;

Heap *init(int size) {
    Heap *p = (Heap *)malloc(sizeof(Heap));
    p->pi = (int *)malloc(sizeof(int) * (size + 1));
    p->di = (int *)malloc(sizeof(int) * (size + 1));
    p->n = 0;
    p->size = size + 1;
    return p;
}

int push(Heap *p, int pi, int di) {
    p->pi[++p->n] = pi;
    p->di[p->n] = di;
    int index = p->n;
    while ((index > 1 && p->pi[index] <= p->pi[index >> 1])) {
        if ((p->pi[index] == p->pi[index >> 1]) && (p->di[index] > p->di[index >> 1])) {
            index >>= 1;
            continue;
        }
        swap(p->pi[index], p->pi[index >> 1]);
        swap(p->di[index], p->di[index >> 1]);
        index >>= 1;
    }
    return 1;
}

int pop(Heap *p) {
    swap(p->pi[1], p->pi[p->n]);
    swap(p->di[1], p->di[p->n]);
    --p->n;
    int index = 1, maxn;
    while (index * 2 <= p->n) {
        maxn = index;
        int index1 = index * 2, index2 = index * 2 + 1;
        if (p->pi[index1] < p->pi[maxn]) maxn = index1;
        else if (p->pi[index1] == p->pi[maxn]){
            if (p->di[index1] < p->di[maxn]) maxn = index1;
        }
        if (index2 <= p->n && p->pi[index2] < p->pi[maxn]) maxn = index2;
        else if (index2 <= p->n && p->pi[index2] == p->pi[maxn]) {
            if (p->di[index2] < p->di[maxn]) maxn = index2;
        }
        if (maxn == index) break;
        swap(p->pi[index], p->pi[maxn]);
        swap(p->di[index], p->di[maxn]);
        index = maxn;
    }
    return 1;
}

int get_top_pi(Heap *p) {
    return p->pi[1];
}

int get_top_di(Heap *p) {
    return p->di[1];
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        Heap *p = init(n);
        for (int i = 0; i < n; i++) {
            int di, pi;
            scanf("%d%d", &pi, &di);
            push(p, pi, di);
        }
        int num = 1, sum = 0;
        while (p->n != 0) {
            int pi = get_top_pi(p);
            int di = get_top_di(p);
            sum = pi;
            if (num % 2 == 1) {
                pop(p);
                push(p, pi + di, di);
            } else {
                pop(p);
            }
            ++num;
        }
        printf("%d\n", sum);
    }
}


