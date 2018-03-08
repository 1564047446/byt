/*************************************************************************
	> File Name: test84.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月25日 星期四 10时46分38秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define ep 0.001
#define swap(a, b) {  \
    __typeof(a) __temp = a;  \
    a = b;  \
    b = __temp;  \
}


typedef struct Heap {
    int n, size;
    double *data;
} Heap;

Heap *init(int size) {
    Heap *h = (Heap *)malloc(sizeof(Heap) * 1);
    h->size = size + 1;
    h->n = 0;
    h->data = (double *)malloc(sizeof(double) * (size + 1));
    return h;
}

int push(Heap *p, double value) {
    if (p->n + 1 == p->size) {
        printf("heap is fulled \n");
        return 0;
    }
    p->data[++p->n] = value;
    int index = p->n;
    while (index > 1 && p->data[index >> 1] < p->data[index]) {
        swap(p->data[index >> 1], p->data[index]);
        index >>= 1;
    }
    return 1;
}

int pop(Heap *p) {
    swap(p->data[1], p->data[p->n]);
    --p->n;
    int index = 1;
    while (index * 2 <= p->n) {
        int index1 = index * 2, index2 = index * 2 + 1;
        int maxn = index;
        if (p->data[maxn] < p->data[index1]) maxn = index1;
        if (index2 <= p->n && p->data[maxn] < p->data[index2]) maxn = index2;
        if (maxn == index) break;
        swap(p->data[index], p->data[maxn]);
        index = maxn;
    }
    return 1;
}

double get_front(Heap *p) {
    return p->data[1];
}

double newton(int n) {
    double x = 1.0;
    n = (double)(n);
    while (fabs(x * x * x - n) > ep) {
        x = x - (x * x * x - n) / (x * x * 3);
        //printf("x = %lf\n", x);
    }
    return x;
}


int main() {
    int n;
    scanf("%d", &n);
    Heap *p = init(n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        x = (double)(x);
        push(p, x);
        //printf("front is = %lf\n", get_front(p));
    }
    while (p->n != 1) {
        double a = get_front(p);
        pop(p);
        double b = get_front(p);
        pop(p);
        push(p, newton(a * b * b));
        printf("newton = %lf\n", newton(a + b));
        //printf("%lf\n", a);
    }
    printf("ans = %12lf\n", get_front(p));
    return 0;
}
