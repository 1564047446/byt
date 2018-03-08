/*************************************************************************
	> File Name: test127.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月05日 星期一 13时49分30秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *left, *right;
    int value;
} Node;

Node *init(int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

Node *insert(Node *node, int value) {
    if (node == NULL) {
        node = init(value);
        return node;
    }
    if (node->value == value) return node;
    if (value > node->value) {
        node->right = insert(node->right, value);
    } else {
        node->left = insert(node->left, value);
    }
}

Node *get_pre_node(Node *node) {
    Node *temp = node;
    while (temp->right) {
        temp = temp->right;
    }
    return temp;
}

Node *delete_ndoe(Node *node, int value) {
    if (node == NULL) return NULL;
    if (value > node->value) {
        node->right = delete_ndoe(node->right, value);
    } else if (value < node->value) {
        node->left = delete_ndoe(node->left, value);
    } else {
        if (node->left == NULL && node->right == NULL) {
            free(node);
            return NULL;
        } else if (node->left == NULL || node->right == NULL) {
            Node *temp;
            temp = (node->left) ? node->left : node->right;
            free(node);
            return temp;
        } else {
            Node *temp = get_pre_node(node->left);
            node->value = temp->value;
            node->left = delete_ndoe(node->left, temp->value);
        }
    }
    return node;
}

void in_order(Node *node) {
    if (node == NULL) return ;
    in_order(node->left);
    printf("%d ", node->value);
    in_order(node->right);
    return ;
}

int main() {
    Node *tree = NULL;
    int op, value;
    while (~scanf("%d", &op)) {
        if (op == -1) break;
        switch (op) {
            case 1: {
                scanf("%d", &value);
                tree = insert(tree, value);
                break;
            }
            case 2: {
                scanf("%d", &value);
                tree = delete_ndoe(tree, value);
                break;
            }
            case 3: {
                in_order(tree);
                printf("\n");
                break;
            }
        }
    }
    return 0;
}
