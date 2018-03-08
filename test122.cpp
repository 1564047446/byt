#include <stdio.h>
#include <stdlib.h>
 
const int SIZE = 26;
const int MAX_LEN_T = 110005;
const int MAX_LEN_S = 2000005;
const char BASE = 'a';
 
typedef struct TrieNode {
    int count, flag;
    struct TrieNode **next;
    struct TrieNode *fail;
    struct TrieNode *pre_word;
} TrieNode, *Trie;
 
TrieNode *new_node() {
    TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode));
    p->next = (TrieNode **)malloc(SIZE * sizeof(TrieNode *));
    memset(p->next, 0, SIZE * sizeof(TrieNode *));
    p->flag = 0;
    p->count = 0;
    p->fail = NULL;
    p->pre_word = NULL;
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
    TrieNode **q = (TrieNode **)malloc((root->count + 2) * sizeof(TrieNode *));
    TrieNode *p, *now;
    int head, tail;
    head = tail = 0;
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
            if (now->flag) {
                p->next[i]->pre_word = now;
            } else {
                p->next[i]->pre_word = now->pre_word;
            }
            q[tail++] = p->next[i];
        }
    }
    free(q);
}
 
void match_ac(Trie root, char *str) {
    TrieNode *p = root, *now;
    while (*str) {
        while (p && p->next[str[0] - BASE] == NULL) {
            p = p->fail;
        }
        if (p == NULL) {
            p = root;
        } else {
            p = p->next[str[0] - BASE];
        }
        now = p;
        while (now) {
            ++(now->count);
            now = now->pre_word;
        }
        ++str;
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
 
int __ind(char ch) {
    if (ch <= BASE + 25 && ch >= BASE) {
        return ch - BASE + 1;
    } else {
        return 0;
    }
}
 
char __char(int num) {
    if (num <= 26 && num > 0) {
        return (char)(num + BASE - 1);
    } else {
        return '$';
    }
}
 

void get_t_origin(char *str) {
    char *o_str = (char *)malloc(MAX_LEN_T * sizeof(char));
    int *ind_arr = (int *)malloc(MAX_LEN_T * sizeof(int));
    int ch_num[27] = {0};
    int len = strlen(str);
    int i, j;
    for (i = 0; i < len; i++) {
        ch_num[__ind(str[i])]++;
    }
    for (j = 0, i = 0; i < 27; i++) {
        while (ch_num[i] > 0) {
            o_str[j++] = __char(i);
            ch_num[i]--;
        }
    }
    for (int i = 0; i < len; i++) {
        j = __ind(o_str[i]);
        while (str[ch_num[j]++] != o_str[i]) ;
        ind_arr[i] = ch_num[j] - 1;
    }
    j = ind_arr[0];
    i = 0;
    while (j) {
        str[i++] = o_str[j];
        j = ind_arr[j];
    }
    str[i] = '\0';
    free(o_str);
    free(ind_arr);
    return ;
}

 

int main() {
    char *t_str = (char *)malloc(MAX_LEN_T * sizeof(char));
    char *str = (char *)malloc(MAX_LEN_S * sizeof(char));
    int **ans_arr;
    Trie root = new_node();
    scanf("%s", t_str);
    get_t_origin(t_str);
    int n;
    scanf("%d", &n);
    ans_arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        ans_arr[i] = insert(root, str);
    }
    build_automaton(root);
    match_ac(root, t_str);
    for (int i = 0; i < n; i++) {
        printf("%s\n", *(ans_arr[i]) ? "YES" : "NO");
    }
    return 0
}