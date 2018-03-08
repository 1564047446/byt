#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};
 
struct TreeNode *init(int val) {
	struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->val = val;
	root->left = root->right = NULL;
	return root;
}

//char s[100];
int num = 0;


void output(struct TreeNode *p, char *s) {
    //static char *s = (char *)malloc(sizeof(char) * 100);
    if (!p) return ;
    //printf("%c", p->val + '0');
    s[num++] = p->val + '0';
    if (p->left == NULL && p->right == NULL) {
        return ;
    }
    //printf("(");
    s[num++] = '(';
    if (p->left) {
        output(p->left, s);
    }
    if (p->right) { 
           //printf(",");
           s[num++] = ',';
        output(p->right, s);
    }
    s[num++] = ')';
    //printf(")");

}

char *get_char(struct TreeNode *root) {
    char *s = (char *)malloc(sizeof(char) * 100);
    output(root, s);
    return s;
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) {
    struct TreeNode **stack = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * strlen(data));
    struct TreeNode *current = NULL;
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root = NULL;
    printf("ok\n");
    int flag = 0, i = 0, top = -1;
    while (data[i]) {
    	switch (data[i]) {
    		case '(':
    			stack[++top] = current;
    			current = NULL;
    			flag = 1;
    			break;
    		case ',':
    			flag = 2;
    			break;
    		case ')':
    			--top;
    			if (top < -1) {
    				printf("error\n");
    				return NULL;
    			}
    			break;
    		default :
    			current = init(data[i] - '0');
    			if (flag == 0) {
    				root = current;
    			} else if (flag == 1) {
    				stack[top]->left = current;
    			} else if (flag == 2) {
    				stack[top]->right = current;
    			}
    			break;
    	}
    	++i;
    }
    return root;
}		

void pre_order(struct TreeNode *root) {
	printf("%d ", root->val);
	if (root->left) pre_order(root->left);
	if (root->right) pre_order(root->right);
}

int main() {
	char str[100];
	scanf("%s", str);
	struct TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
	root = deserialize(str);
	//pre_order(root), printf("\n");
	//printf("%s\n", s);
	char *q = (char *)malloc(sizeof(char) * 100);
	//q = serialize(root);
	//printf("%s\n", q);
	//output(root); printf("\n");
    char *s1 = (char *)malloc(sizeof(char) * 110);
    s1 = get_char(root);
    printf("%s\n", s1);
}