#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ({\
	__typeof(a) tempa = a;\
	__tyepof(b) tempb = b;\
	tempa > tempb ? tempa : tempb;\
})

typedef struct BBSTree {
	int value, hight;
	struct BBSTree *left, *right;
} BBSTree;

BBSTree __NIL;
#define NIL &(__NIL)
void init() {
	NIL->value = 0, NIL->hight = 0;
	NIL->left = NIL->right = NIL;
	return ;
}

BBSTree *get_node(int value) {
	BBSTree *p = (BBSTree *)malloc(sizeof(BBSTree));
	p->hight = 1, p->value = value;
	p->left = p->right = NIL;
	return p;
}

BBSTree *update_hight(BBSTree *node) {
	node->hight = max(root->left->hight, root->right->hight) + 1;
	return node;
}

BBSTree *insert(BBSTree *root, int value) {
	if (root == NULL) {
		root = get_node(value);
		return root;
	}
	if (value < root->value) {
		root->left = insert(root->left, value);
	} else if (value > root->value) {
		root->right = insert(root->right, value);
	} else {
		return root;
	}
	root = update_hight(root);
	
}

