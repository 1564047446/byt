/*************************************************************************
	> File Name: test68.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月19日 星期五 20时08分38秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char value;
    struct Node *left, *right;
} Node, *Btree;

Btree init(char value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->right = NULL;
    node->left = NULL;
    return node;
}

void build(Btree &root, char *str, int i, int n) {
    //root = (Node *)malloc(sizeof(Node));
    if (n <= 0) return ;
    if (i > n) return ;
    root = init(str[i]);
    //printf("%c\n", str[i]);
    if (2 * i <= n) {
        build(root->left, str, 2 * i, n);
    }
    if ((2 * i + 1) <= n) {
        build(root->right, str, 2 * i + 1, n);
    }
}

void pre_order(Btree root) {
    printf("%c ", root->value);
    if (root->left != NULL) pre_order(root->left);
    if (root->right != NULL) pre_order(root->right);
}

void print(Node *node) {
    if (node == NULL) return;
    printf("%c", node->value);
    if (node->left != NULL) {
        printf("(");
        print(node->left);
        if (node->right == NULL) {
            printf(")");
        }
    }
    if (node->right != NULL) {
        if (node->left == NULL) {
            printf("(");
        }
        printf(",");
        print(node->right);
        printf(")");
    }
    return ;
}

int main() {
    char str[100];
    scanf("%[^\n]s", str);
    char digit[100];
    int num = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            digit[++num] = str[i];
        }
    }
    /*for (int i = 1; i <= num; i++) {
        printf("%c", digit[i]);
    }*/
    Node *root = (Node *)malloc(sizeof(Node));
    build(root, digit, 1, num);
    //pre_order(root);
    print(root), printf("\n");
    return 0;
}
