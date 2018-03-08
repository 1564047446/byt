/*************************************************************************
	> File Name: test48.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月12日 星期五 14时50分10秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int size, length;
    int *data;
} Node;

void init(Node *node, int size) {
    node->size = size;
    node->length = 0;
    node->data =  (int *)malloc(sizeof(int) * size);
}

int insert(Node *node, int value, int locate) {
    if (locate < 0 || locate > node->length) return 0;
    for (int i = node->length; i > locate; i--) {
        node->data[i] = node->data[i - 1];
    }
    node->data[locate] = value;
    node->length++;
    return 1;
}


int search(Node *node, int value) {
    for (int i = 0; i < node->length; i++) {
        if (node->data[i] == value) {
            return 1;
        }
    }
    return 0;
}

int main() {
    Node *node = (Node *)malloc(sizeof(Node));
    int a;
    scanf("%d", &a);
    init(node, a);
    for (int i = 0; i < a; i++) {
        int n;
        scanf("%d", &n);
        insert(node, n, i);
    }
    int b;
    scanf("%d", &b);
    int a1[100];
    int num = 0;
    for (int i = 0; i < b; i++) {
        scanf("%d", a1 + i);
        if (search(node, a1[i])) {
            num++;
        }
    }
    printf("%d\n", num);
    int k = 0;
    for (int i = 0; i < b; i++) {
        if (search(node, a1[i])) {
            if(k == 0) printf("%d", a1[i]), k++;
            else printf(" %d", a1[i]);
        }
    }
    printf("\n");
    return 0;
}
