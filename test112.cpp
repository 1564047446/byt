/*************************************************************************
	> File Name: test112.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年02月13日 星期二 14时50分39秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TrieNode {
    struct TrieNode *child[26];
    struct TrieNode *fail;
    int flag;
} TrieNode;

TrieNode *get_node() {
    TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode));
    p->fail = NULL;
    for (int i = 0; i < 26; ++i) {
        p->child[i] = NULL;
    }
    p->flag = 0;
    return p;
}

int insert(TrieNode *p, const char *str) {
    if (p == NULL) return 0;
    int times = 0;
    while (str[0]) {
        if (p->child[str[0] - 'a'] == NULL && p != NULL) {
            p->child[str[0] - 'a'] = get_node();
            ++times;
        }
        p = p->child[str[0] - 'a'];
        ++str;
    }
    p->flag = 1;
    return times;
}

int build_automaton(TrieNode  *tree, int n) {
    if (tree == NULL) return 0;
    tree->fail = NULL;
    TrieNode *queue[n + 10];
    int head = 0, tail = 0;
    queue[tail++] = tree;
    while (head < tail) {
        TrieNode *p = queue[head++], *q;
        for (int i = 0; i < 26; ++i) {
            if (p != NULL && p->child[i] == NULL) continue;
            q = p->fail;
            while (q != NULL && q->child[i] == NULL) q = q->fail;
            if (q == NULL) q = tree;
            else q = q->child[i];
            p->child[i]->fail = q;
            queue[tail++] = p->child[i];
        }
    }
    return 1;
}

int search_automaton(TrieNode *ac_tree, const char *str) {
    if (ac_tree == NULL) return 0;
    TrieNode *p = ac_tree, *q;
    int cnt = 0;
    while (str[0]) {
        while (p != NULL && p->child[str[0] - 'a'] == NULL) p = p->fail;
        if (p) p = p->child[str[0] - 'a'];
        else p = ac_tree;
        q = p;
        while (q) cnt += q->flag, q = q->fail;
        ++str;
    }
    return cnt;
}

int main() {
    char s[100];
    TrieNode *p = get_node();
    int n, m, cnt;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        cnt += insert(p, s);
    }
    char buffer[100];
    scanf("%s", buffer);
    build_automaton(p, cnt);
    int ans = search_automaton(p, buffer);
    printf("%d\n", ans);
}
