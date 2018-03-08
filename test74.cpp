#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};
 
struct TreeNode *init(int val) {
	struct TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
	root->val = val;
	root->left = root->right = NULL;
	return root;
}

//char s[100];
int num = 0;

char* serialize(struct TreeNode* root) {
	char *s = (char *)malloc(sizeof(char) * 100);
	struct TreeNode **q = (TreeNode **)malloc(sizeof(TreeNode *) * 100);
	int head = 0, tail = -1, flag = 1;
	q[++tail] = root;
	//s[num++] = root->val + '0';
	while (tail != -1) {
		s[num++] = q[tail]->val + '0';
		current = q[top];
		q[++tail] = current->left;
		q[++tail] = current->right;
		switch (flag) {
			case 0:
				s[num++] = '(';
				flag = 1;
				break;
			case 1:
				if (q[head]->right == NULL) {
					s[num++] = ')';
					flag = 1;
					break;
				} else {
					s[num++] = ',';
					flag = 2;
					break;
				}
			case 2:
			default :
		}
		++head, ++i;
	}
	return s;

}


void output(struct Node *p) {
    if (!p) return ;
    printf("%c", p->data);
    if (p->lchild == NULL && p->rchild == NULL) {
        return ;
    }
    printf("(");
    if (p->lchild) {
        output(p->lchild);
    }
    if (p->rchild) { 
           printf(",");
        output(p->rchild);
    }

    printf(")");

}
/** Decodes your encoded data to tree. */
/*struct TreeNode* deserialize(char* data) {
    struct TreeNode **stack = (TreeNode **)malloc(sizeof(TreeNode *) * strlen(data));
    struct TreeNode *current = NULL;
    struct TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode *));
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
}*/	 		

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
	pre_order(root), printf("\n");
	//printf("%s\n", s);
	char *q = (char *)malloc(sizeof(char) * 100);
	//q = serialize(root);
	//printf("%s\n", q);
	output(), printf("\n");
}