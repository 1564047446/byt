/*************************************************************************
	> File Name: test78.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月24日 星期三 10时25分46秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

struct TreeNode *init(int val) {
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = val;
    root->left = root->right = NULL;
    return root;
}

int num = 0;

void get_char(struct TreeNode *root, char *str) {
    if (root == NULL) return ;
    if (root->val == 0) {
        str[num++] = '0';
    }
    else if (root->val > 0) {
        int num1 = 0, n = root->val;
        char s[1000];
        while (n) {
            s[num1++] = n % 10 + '0';
            n /= 10;
        }
        int j = 0;
        while (num1--) {
            str[num++] = s[num1];
        }
    } else {
        int num1 = 0, n = -root->val;
        str[num++] = '-';
        char s[1000];
        while (n) {
            s[num1++] = n % 10 + '0';
            n /= 10;
        }
        while (num1 --) {
            str[num++] = s[num1];
        }
    }
    if (root->left == NULL && root->right == NULL) return ;
    str[num++] = '(';

    if (root->left) {
        get_char(root->left, str);
    }
    if (root->right) {
        str[num++] = ',';
        get_char(root->right, str);
    }
    str[num++] = ')';
}

char *serialize(struct TreeNode *root) {
    char *str = (char *)malloc(sizeof(char) * 100);
    num = 0;
    get_char(root, str);
    str[num] = '\0';
    return str;
}

struct TreeNode *deserialize(char *data) {
    struct TreeNode **s = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * strlen(data));
    struct TreeNode *current = NULL;
    struct TreeNode *root = NULL;
    int top = -1, flag = 0, i = 0;
    while (data[i]) {
        switch (data[i]) {
            case '(':
                s[++top] = current;
                   flag = 1;
                current = NULL;
                break;
            case ',':
                flag = 2;
                break;
            case ')':
                --top;
                break;
            default :
                int num1 = 0, j = i, flag2 = 1;
                if (data[i] == '-') flag2 = 0;
                if (flag2 == 0) ++j;
                for (; j < strlen(data) ; j++) {
                    if (data[j] >= '0' && data[j] <= '9') {
                        num1 = num1 * 10 + data[j] - '0';
                    } else break;
                    //printf("%c ", data[j]);
                } 
                i = j - 1;
                if (flag2) current = init(num1);
                else current = init(-num1);
                if (flag == 0) {
                    root = current;
                } else if (flag == 1) {
                    s[top]->left = current;
                } else if (flag == 2) {
                    s[top]->right = current;
                }
                break;
        }
        ++i;
    }
    free(s);
    return root;
}

void clear(struct TreeNode *root) {
    if (root->left) clear(root->left);
    if (root->right) clear(root->right);
    free(root);
}

void pre_order(struct TreeNode *root) {
    if (root == NULL) return ;
    printf("%d ", root->val);
    if (root->left) pre_order(root->left);
    if (root->right) pre_order(root->right);
}

int main() {
    char s[100];
    scanf("%s", s);
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root = deserialize(s);
    pre_order(root), printf("pre_order() \n");
    char *str = serialize(root);
    printf("%s\n", str);
    return 0;
}
