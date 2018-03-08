#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};



struct TreeNode *init(int value) {
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = value;
    root->left = root->right = NULL;
    return root;
}

void get_char(struct TreeNode *root, int *num, char *str) {
    if (root == NULL) return;
    //str[(*num)++] = root->val + '0';
    if (root->val > 0) {
        int num_q = 0, n = root->val;
        char s[100000];
        while (n) {
            int k = n % 10;
            s[num_q++] = k + '0';
            n /= 10;
        }
        while (num_q--) {
            str[(*num)++] = s[num_q];
        }
    } else if(root->val < 0) {
        int num_q = 0, n = -root->val;
        str[(*num)++] = '-';
        char s[100000];
        while (n) {
            int k = n % 10;
            s[num_q++] = k + '0';
            n /= 10;
        }
        while (num_q--) {
            str[(*num)++] = s[num_q];
        }
    } else {
        str[(*num)++] = '0';
    }
    if (root->left == NULL && root->right == NULL) return ;
    str[(*num)++] = '(';
    if (root->left) get_char(root->left, num, str);
    if (root->right) {
        str[(*num)++] = ',';
        get_char(root->right, num, str);
    }
    str[(*num)++] = ')';
}

char* serialize(struct TreeNode* root) {
    int num = 0;
    char *s = (char *)malloc(sizeof(char) * 100000);
    get_char(root, &num, s);
    s[num] = '\0';
    return s;
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) {
    struct TreeNode *s[100000];
    struct TreeNode *root = NULL, *current = NULL;
    int top = -1, i = 0, flag = 0, digit = 1;
    while (data[i]) {
        switch (data[i]) {
            case '(' : {
                s[++top] = current;
                current = NULL;
                flag = 1;
                break;
            }
            case ')': {
                --top;
                break;
            }
            case ',': {
                flag = 2;
                break;
            }
            case '-': {
                digit = -1;
                break;
            }
            default : {
                if (digit != -1) {
                    int num = 0;
                    while (data[i] >= '0' && data[i] <= '9') {
                        num = num * 10 + data[i] - '0';
                        ++i;
                    }
                    current = init(num);
                    digit = 1;
                    --i;
                } else {
                    //++i;
                    int num = 0;
                    //printf("%c\n", data[i]);
                    while (data[i] >= '0' && data[i] <= '9') {
                        num = num * 10 + data[i] - '0';
                        ++i;
                    }
                    //printf("num = %d\n", num);
                    current = init(-num);
                    digit = 1;
                    --i;
                }
                //current = init(data[i] - '0');
                if (flag == 0) {
                    root = current;
                } else if (flag == 1) {
                    s[top]->left = current;
                } else if (flag == 2) {
                    s[top]->right = current;
                }
            }
        }
        ++i;
    }
    return root;
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
    struct TreeNode *root;
    root = deserialize(s);
    pre_order(root);
    printf("\n");
    char *s1 = serialize(root);
    printf("result = %s\n", s1);
    return 0;
}