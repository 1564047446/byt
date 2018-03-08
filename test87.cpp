
#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) {  \
    __typeof(a) __temp = a;  \
    a = b;  \
    b = __temp;  \
}

typedef struct Heap {
    int *data;
    int n, size;
} Heap;

Heap *init(int size) {
    Heap *p = (Heap *)malloc(sizeof(Heap));
    p->data = (int *)malloc(sizeof(int) * (size + 1));
    p->n = 0;
    p->size = size + 1;
}


int push(Heap *p, int value) {
    if (p->n + 1 >= p->size) return 0;
    p->data[++p->n] = value;
    int index = p->n;
    while (index > 1 && p->data[index >> 1] > p->data[index]) {
        swap(p->data[index >> 1], p->data[index]);
        index >>= 1;
    }
    return 1;
}

int pop(Heap *p) {
    swap(p->data[1], p->data[p->n]);
    int index = 1;
    --p->n;
    while (index * 2 <= p->n) {
        int index1 = 2 * index, index2 = 2 * index + 1;
        int maxn = index;
        if (p->data[index1] < p->data[maxn]) maxn = index1;
        if (index2 <= p->n && p->data[index2] < p->data[maxn]) maxn = index2;
        if (maxn == index) break;
        swap(p->data[index], p->data[maxn]);
        index = maxn;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    Heap *p = init(n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        push(p, a);
    }
    for (int i = 1; i <= n; i++) {
        if (i == 1) printf("%d", p->data[1]);
        else printf(" %d", p->data[1]);
        pop(p);
    }
    printf("\n");
    return 0;
}
