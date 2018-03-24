#include <stdio.h>
#include <stdlib.h>

#define max(a, b) a > b ? a : b

typedef struct AVLTree {
	int value, hight;
	struct AVLTree *left, *right;
} AVLTree;

AVLTree __NIL;

#define NIL (&__NIL)

int init() {
	NIL->left = NIL;
	NIL->right = NIL;
	NIL->hight = 0;
	return 0;
}

int q = init();

AVLTree *get_node(int value) {
	AVLTree *p = (AVLTree *)malloc(sizeof(AVLTree));
	p->left = p->right = NIL;
	p->hight = 1;
	p->value = value;
	return p;
}

void up(AVLTree *root) {
	root->hight = max(root->left->hight, root->right->hight) + 1;
}

AVLTree *left_rorate(AVLTree *root) {
	AVLTree *temp = root->right;
	root->right = temp->left;
	temp->left = root;
	up(root);
	up(temp);
	return temp;
}

AVLTree *right_rorate(AVLTree *root) {
	AVLTree *temp = root->left;
	root->left = temp->right;
	temp->right = root;
	up(root);
	up(temp);
	return temp;
}

AVLTree *rorate_tree(AVLTree *tree) {
	if (tree->left->hight > tree->right->hight) {
		if (tree->left->right->hight > tree->left->left->hight) {
			tree->left = left_rorate(tree->left);
		}
		tree = right_rorate(tree);
	} else {
		if (tree->right->left > tree->right->right) {
			tree->right = right_rorate(tree->right);
		}
		tree = left_rorate(tree);
	}
	return tree;	
}

AVLTree *Balance_tree(AVLTree *root) {
	if (abs(root->left->hight - root->right->hight) < 2) return root;
	root = rorate_tree(root);
	return root;
}

AVLTree *insert(AVLTree *root, int value) {
	if (root == NIL) {
		return get_node(value);
	} else if (value > root->value) {
		root->right = insert(root->right, value);
	} else if (value < root->value) {
		root->left = insert(root->left, value);
	} else if (root->value == value) return root;
	up(root);
	root = Balance_tree(root);
	return root;
}

void pre_order(AVLTree *root) {
    if (root == NIL) return ;
    printf("%d (%d, %d)\n", root->value, root->left->value, root->right->value);
    pre_order(root->left);
    pre_order(root->right);
    return ;
}

int main() {
    int n;
    AVLTree *root = NIL;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        root = insert(root, a);
        printf("Tree info :\n");
        pre_order(root);
        printf("_____________\n");
    }
    //clear(root);
    return 0;
}