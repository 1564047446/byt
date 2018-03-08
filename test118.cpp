#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct TrieNode {
	struct TrieNode *child[26], *fail;
	int count, flag;
} TrieNode;

TrieNode *new_node() {
	TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode));
	p->fail = NULL;
	p->flag = 0, p->count = 0;
	for (int i = 0; i < 26; i++) {
		p->child[i] = NULL;
	}
	return p;
}

int *insert(TrieNode *p, char *str) {
	while (str[0]) {
		if (p->child[str[0] - 'a'] == NULL) p->child[str[0] - 'a'] = new_node();
		p = p->child[str[0] - 'a'];
		++str;
	}
	p->flag = 1;
	return &p->count;
}

void build_automaton(TrieNode *tree, int n) {
	tree->fail = NULL;
	TrieNode *queue[n + 10];
	int head = 0, tail = 0;
	queue[tail++] = tree;
	while (head < tail) {
		TrieNode *p = queue[head++], *q;
		for (int i = 0; i < 26; i++) {
			if (p->child[i] == NULL) continue;
			q = p->fail;
			while (q != NULL && q->child[i] == NULL) q = q->fail;
			if (q == NULL) q = tree;
			else q = q->child[i];
			p->child[i]->fail = q;
			queue[tail++] = p->child[i];
		}
	}
}

void search_automaton(TrieNode *ac_tree, char *str) {
	TrieNode *p = ac_tree, *q;
	while (str[0]) {
		while (p != NULL && p->child[str[0] - 'a'] == NULL) p = p->fail;
		if (p == NULL) p = ac_tree;
		else p = p->child[str[0] - 'a'];
		q = p;
		while (q) q->count += q->flag, q = q->fail;
		++str;
	}
}

int main() {
	int n, maxn = 0;
	scanf("%d", &n);
	TrieNode *p = new_node();
	int *queue[n];
	char str[30], buffer[100030];
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		queue[i] = insert(p, str);
		maxn += strlen(str);
	}
	build_automaton(p, maxn);
	scanf("%s", buffer);
	search_automaton(p, buffer);
	for (int i = 0; i < n; i++) printf("%d: %d\n", i, *queue[i]);
	return 0;
}