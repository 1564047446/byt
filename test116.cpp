/*************************************************************************
	> File Name: test116.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年02月19日 星期一 22时22分32秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TrieNode {
    struct TrieNode *child[26];
    int cnt;
} TrieNode;

TrieNode *new_node() {
    TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode));
    p->cnt = 0;
    for (int i = 0; i < 26; i++) p->child[i] = NULL;
    return p;
}

int insert(TrieNode *p, char *str) {
    TrieNode *root = p;
    while (str[0]) {
        if (p->child[str[0] - 'a'] == NULL) {
            p->child[str[0] - 'a'] = new_node();
            ++root->cnt;
        }
        p = p->child[str[0] - 'a'];
        ++str;
    }
    return 1;
}

int main() {
    while (~scanf("%d", &n))  {
        TrieNode *p = new_node();
        int n, maxn = 0;
        char str[100];
        for (int i = 0; i < n; i++) {
        scanf("%s", str);
        insert(p, str);
        maxn = maxn > strlen(str) ? maxn : strlen(str);
    }
    //printf("cnt = %d\n", p->cnt);
    printf("%d\n", p->cnt * 2 + n - maxn);}
    return 0;
}
