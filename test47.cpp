/*************************************************************************
	> File Name: test47.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月12日 星期五 14时11分17秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct Node {
    int size, length;
    int *c, *e;
} Node;


void init(Node *node, int size) {
    node->size = size;
    node->length = 0;
    node->c = (int *)malloc(sizeof(int) * size);
    node->e = (int *)malloc(sizeof(int) * size);
}

int insert(Node *node, int value1, int value2, int index) {
    if (index < 0 || index > node->length) return 0;
    for (int i = node->length; i > index; i--) {
        node->c[i] = node->c[i - 1];
        node->e[i] = node->e[i - 1];
    }
    node->c[index] = value1;
    node->e[index] = value2;
    node->length++;
    return 1;
}
int power(int a, int b);

int cal(Node *node, int x) {
    int sum = 0;
    for (int i = 0; i < node->length; i++) {
        sum += node->c[i] * (power(x, node->e[i]));
    }
    return sum;
}

int power(int a, int b) {
    if (b == 0) return 1;
    int sum = 1;
    for (int i = 1; i <= b; i++) {
        sum *= a;
    }
    return sum;
}

int main() {
    Node *node = (Node *)malloc(sizeof(Node));
    int m;
    scanf("%d", &m);
    init(node, m);
    for (int i = 0; i < m; i++) {
        int e, c;
        scanf("%d%d", &c, &e);
        insert(node, c, e, i);
    }
    int x;
    scanf("%d", &x);
    printf("%d\n", cal(node, x));
}
