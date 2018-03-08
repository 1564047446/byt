#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*段错误修改完毕*/
const int SIZE = 26;
const char BASE = 'a';
const int MAX_SIZE = 200010;
const int MAX_LEN = 200000;


typedef struct TrieNode {
    int count;
    struct TrieNode** childs;
    struct TrieNode* fail;
} TrieNode, *Trie;

TrieNode* new_node() {
    TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode));
    p->childs = (TrieNode **)malloc(sizeof(TrieNode *) * SIZE);
    for (int i = 0; i < SIZE; i++) {
        p->childs[i] = NULL;
    }
    p->fail = NULL;
    p->count = 0;
    return p;
}

void clear() {
    
}

void insert(Trie trie, char *buffer) {
    TrieNode *p = trie;
    for (int i = 0; i < strlen(buffer); i++) {
        if (p->childs[buffer[i] - BASE] == NULL) {
            p->childs[buffer[i] - BASE] = new_node();
        }
        p = p->childs[buffer[i] - BASE];
    }
    p->count++;
}

void build_automaton(Trie root) {
    root->fail = NULL;
    TrieNode *q[MAX_SIZE];
    int l = 0, r = 0;
    q[r++] = root;
    while (l < r) {
        TrieNode *now = q[l++];
        for (int i = 0; i < SIZE; i++) {
            if (now->childs[i] != NULL) {
                TrieNode *child = now->childs[i];
                if (now == root) {
                    child->fail = root;
                } else {
                    TrieNode *iter = now;
                    while (iter != NULL && iter->childs[i] == NULL) {
                        iter = iter->fail;
                    }
                    if (iter->fail->childs[i] != NULL) {
                        child->fail = iter->fail->childs[i];
                    } else {
                        child->fail = root;
                    }
                }
                q[r++] = child;
            }
        }
    }
}

int match_count(Trie root, const char *buffer) {
    TrieNode *p = root;
    int cnt = 0;
    for (int i = 0; buffer[i]; i++) {
        while (p != root && p->childs[buffer[i] - BASE] == NULL) {
            p = p->fail;
        }
        p = p->childs[buffer[i] - BASE];
        if (p == NULL) {
            p = root;
        }
        TrieNode *iter = p;
        while (iter != root) {
            cnt += iter->count;
            //iter->count = 0;
            iter = iter->fail;
        }
    }
    return cnt;
}

int main() {
    Trie root = new_node();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char pattern[100];
        scanf("%s", pattern);
        insert(root, pattern);
    }
    build_automaton(root);
    char str_buffer[MAX_LEN];
    scanf("%s", str_buffer);
    printf("%d\n", match_count(root, str_buffer));
    return 0;
}
