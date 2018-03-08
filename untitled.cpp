#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
const int MAX_LEN = 100005;
const int SIZE = 26;
const char BASE = 'a';
 
typedef struct TrieNode {
    int count, flag;
    struct TrieNode **next;
    struct TrieNode *fail;
} TrieNode, *Trie;
 
TrieNode *new_node() {
    TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode));
    p->next = (TrieNode **)malloc(SIZE * sizeof(TrieNode *));
    memset(p->next, 0, SIZE * sizeof(TrieNode *));
    p->count = 0;
    p->flag = 0;
    return p;
}
 
int *insert(Trie root, char *str) {
    TrieNode *p = root;
    while (*str) {
        if (p->next[str[0] - BASE] == NULL) {
            p->next[str[0] - BASE] = new_node();
            ++(root->count);
        }
        p = p->next[str[0] - BASE];
        ++str;
    }
    p->flag = 1;
    return &(p->count);
}
 
void build_automaton(Trie root) {
    TrieNode *p, *now;
    TrieNode **q = (TrieNode **)malloc(root->count * sizeof(TrieNode *));
    int head = 0, tail = 0;
    root->fail = NULL;
    q[tail++] = root;
    while (head < tail) {
        p = q[head++];
        for (int i = 0; i < SIZE; i++) {
            if (p->next[i] == NULL) continue;
            now = p->fail;
            while (now && now->next[i] == NULL) {
                now = now->fail;
            }
            if (now == NULL) {
                now = root;
            } else {
                now = now->next[i];
            }
            p->next[i]->fail = now;
            q[tail++] = p->next[i];
        }
    }
}
 
void clear(Trie root) {
    if (!root) return ;
    for (int i = 0; i < SIZE; i++) {
        if (root->next[i] == NULL) continue;
        clear(root->next[i]);
    }
    free(root);
}
 
void match_ac(Trie root, char *buffer) {
    TrieNode *p = root, *now;
    while (*buffer) {
        while (p && p->next[buffer[0] - BASE] == NULL) {
            p = p->fail;
        }
        if (p) {
            p = p->next[buffer[0] - BASE];
            now = p;
            while (now) {
                now->count += now->flag;
                now = now->fail;
            }
        } else {
            p = root;
        }
        ++buffer;
    }
}
 
void solve(int n) {
    Trie root = new_node();
    char *buffer = (char *)malloc(MAX_LEN * sizeof(char));
    int **ans_num = (int **)calloc(n, sizeof(int *));
    char str[55];
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        ans_num[i] = insert(root, str);
    }
    build_automaton(root);
    scanf("%s", buffer);
    match_ac(root, buffer);
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", i, *ans_num[i]);
    }
    clear(root);
    free(buffer);
    free(ans_num);
}
 
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        solve(n);
    }
    return 0;
}
 

 
