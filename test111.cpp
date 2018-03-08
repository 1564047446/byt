/*************************************************************************
	> File Name: test111.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年02月12日 星期一 11时46分50秒
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
    p->flag = 0;
    p->fail = NULL;
    for (int i = 0; i < 26; i++) {
        p->child[i] = NULL;
    }
    return p;
}

int insert(TrieNode *p, const char *str) {
    int cnt = 0;
    while (str[0]) {
        if (p->child[str[0] - 'a'] == NULL) {
            p->child[str[0] - 'a'] = get_node();
            ++cnt;
        }
        p = p->child[str[0] - 'a'];
        ++str;
    }
    p->flag = 1;
    return cnt;
}

int build_automaton(TrieNode *p, int n) {
    if (p == NULL) return 0;
    p->fail = NULL;
    TrieNode **queue = (TrieNode **)malloc(sizeof(TrieNode *) * (n + 10));
    int head = 0, tail = 0;
    queue[tail++] = p;
    while (head < tail) {
        TrieNode *q1 = queue[head++], *q2;
        for (int i = 0; i < 26; ++i) {
            if (q1->child[i] == NULL) continue;
            q2 = q1->fail;
            while (q2 != NULL && q2->child[i] == NULL) {
                q2 = q2->fail;
            }
            if (q2) q2 = q2->child[i];
            else q2 = p;
            q1->child[i]->fail = q2;
            queue[tail++] = q1->child[i];
        }
    }
    return 1;
}

int search_automaton(TrieNode *ac_tree, const char *str) {
    int cnt = 0;
    TrieNode *p = ac_tree, *q;
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
    
    return 0;
}
