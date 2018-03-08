/*************************************************************************
	> File Name: test69.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月20日 星期六 11时28分40秒
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
    node->left = NULL;
    node->right = NULL;
    return node;
}

Btree build(Node *node, char pos, char value, char direct) {
    if (node->value == pos && node != NULL) {
        if (direct == 'L') {
            node->left = init(value);
            return node;
        }
        else {
            node->right = init(value);
            return node;
        }
    }
    if (node->left != NULL) build(node->left, pos, value, direct);
    if (node->right != NULL) build(node->right, pos, value, direct);
}

void pre_order(Node *root) {
    printf("%c", root->value);
    if (root->left != NULL) pre_order(root->left);
    if (root->right != NULL) pre_order(root->right);
}

void print(Node *root) {
    if (root) printf("%c", root->value);
    if (root->left != NULL) {
        printf("(");
        print(root->left);
        if (root->right == NULL) printf(")");
    }
    if (root->right != NULL) {
        if (root->left == NULL) printf("(");
        printf(",");
        print(root->right);
        printf(")");
    }
}

int main() {
    char s[3];
    Node *root = (Node *)malloc(sizeof(Node));
    while (1) {
        scanf("%s", s);
        if (s[0] == '^' && s[1] != '^') root = init(s[1]);
        if (s[0] == '^' && s[1] =='^') break;
        if (s[0] != '^') build(root, s[0], s[1], s[2]);
    }
    if (root == NULL) printf("\n");
    else print(root), printf("\n");
    return 0;
}
