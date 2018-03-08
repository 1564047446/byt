/*************************************************************************
	> File Name: test49.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月12日 星期五 15时09分18秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int size, length;
    int *id;
} Node;


void init(Node *node, int size) {
    node->size = size;
    node->length = 0;
    node->id = (int *)malloc(sizeof(int) * size);
}

int insert(Node *node, int value, int index) {
    if (index < 0 || index > node->length) return 0;
    for (int i = node->length; i < index; i--) {
        node->id[i] = node->id[i - 1];
    }
    node->id[index] = value;
    node->length++;
    return 1;
}

int delete_node(Node *node, int index) {
    for (int i = index; i < node->length - 1; i++) {
        node->id[i] = node->id[i + 1];
    }
    node->length--;
    return 1;
}

void print(Node *node, int index) {
    printf("%d\n", node->id[index]);
}

int main() {
    Node *node = (Node *)malloc(sizeof(Node));
    int n, m;
    scanf("%d%d", &n, &m);
    init(node, n);
    for (int i = 1; i <= n; i++) {
        insert(node, i, i - 1);
    }
    for (int i = 0; i < m; i++) {
        int key;
        scanf("%d", &key);
        delete_node(node, key - 1);
    }
    int num = node->length / 2;
    print(node, num);
}
