/*************************************************************************
	> File Name: test67.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月19日 星期五 15时15分04秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Node {
    char value;
    struct Node *left, *right;
} Node, *BinatyTree;


BinatyTree init(char value) {
    Node *root = (Node *)malloc(sizeof(Node));
    root->value = value;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void clear(Node *tree) {
    if (tree->left != NULL) clear(tree->left);
    if (tree->right != NULL) clear(tree->right);
    free(tree);
}


BinatyTree build(char *str, int i, int len) {
    Node *root = NULL;
    Node *current = NULL;
    int flag = 0;
    Node **s = (Node **)malloc(sizeof(Node *) * len);
    int top = -1;
    while (str[i]) {
        switch (str[i]) {
            case '(': 
                s[++top] = current;
                flag = 1;
                   break;
            case ',':
                flag = 2;
                break;
            case ')':
                top--;
                break;
            default :
                current = init(str[i]);
                if (root == NULL) root = current;
            else {
                if (flag == 1) {
                    s[top]->left = current;
                } else {
                    s[top]->right = current;
                }
            }
                
        }
        ++i;
    }
    free(s);
    return root;
}

void pre_order(BinatyTree root) {
    printf("%c ", root->value);
    if (root->left != NULL) pre_order(root->left);
    if (root->right != NULL) pre_order(root->right);
}

void print(Node *root) {
    if (root == NULL) return ;
    printf("%c", root->value);
    if (root->left != NULL) {
        printf("(");
        print(root->left);
        if (root->right == NULL) printf(")");
    }
    if (root->right != NULL) {
        if (root->left == NULL) {
            printf("(");
        }
        printf(",");
        print(root->right);
        printf(")");
    }
}

void search(BinatyTree root, char c) {
    if (root == NULL) return ;
    if (root->left && root->left->value == c) {
        //clear(root->left);
        root->left = NULL;
        return ;
    }
    if (root->right && root->right->value == c) {
        //clear(root->right);
        root->right = NULL;
        return ;
    }
    //if (root == NULL) return ;
    if (root->left != NULL) search(root->left, c);
    if (root->right != NULL) search(root->right, c);
    return ;
}

void search2(BinatyTree root, char c) {
    if (root == NULL) return ;
    if (root->value == c) {
        clear(root);
        return ;
    }
    if (root->left != NULL) {
        search2(root->left, c);
    }
    if (root->right != NULL) {
        search2(root->right, c);
    }
}


int main() {
    char str[1000];
    char k;
    scanf("%s%c", str, k);
    //scanf("%c", &k);
    getchar();
    BinatyTree root = (Node *)malloc(sizeof(Node));
    root = build(str, 0, strlen(str));
    printf("k = %d\n", k);
    printf("str = %s, len = %d\n", str, strlen(str));
    pre_order(root), printf("\n");
    if (root->value == k) printf("\n");
    else search(root, k), printf("hello\n"), fflush(stdout), print(root), printf("\n");
    return 0;
}
