/*************************************************************************
	> File Name: test66.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月19日 星期五 14时37分09秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char s;
    struct Node *left, *right;
} Node, *Btree;

Btree init(char value) {
    struct Node *node = (Node *)malloc(sizeof(Node));
    node->s = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void clear(Btree tree) {
    if (tree->left != NULL) clear(tree->left);
    if (tree->right != NULL) clear(tree->right);
    free(tree);
}

Node *get_tree(char *pre, char *in, int len_in) {
    Node *root = init(pre[0]);
    int pos = strchr(in, pre[0]) - in;
    if (pos > 0) {
        root->left = get_tree(pre + 1, in, pos);
    }
    if (len_in - pos - 1 > 0) {
        root->right = get_tree(pre + pos + 1, in + pos + 1, len_in - pos - 1);
    }
    return root;
}
void post_order(Btree root) {
    if (root->left != NULL) post_order(root->left);
    if (root->right != NULL) post_order(root->right);
    printf("%c", root->s);
}

Node *reverse(Node *root) {
    Node *root2 = init(root->s);
    if (root->left != NULL) {
        root2->right = reverse(root->left);
    }
    if (root->right != NULL) {
        root2->left = reverse(root->right);
    }
    return root2;
}

int main() {
    char s1[100], s2[100];
    scanf("%s%s", s1, s2);
    Node *root = (Node *)malloc(sizeof(Node));
    root = get_tree(s1, s2, strlen(s2));
    post_order(root);
    printf("\n");
    Node *root2 = (Node *)malloc(sizeof(Node));
    root2 = reverse(root);
    post_order(root2);
    printf("\n");
    clear(root);
    clear(root2);
    return 0;
}
