#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct Trie {
    struct Trie *child[256];
    int flag;
} Trie;

Trie *get_node() {
    Trie *root = (Trie *)malloc(sizeof(Trie));
    for (int i = 0; i < 256; i++) {
        root->child[i] = NULL;
    }
    root->flag = 0;
    return root;
}

int insert(Trie *root, char *str) {
    while (str[0]) {
        if (root->child[str[0]] == NULL) {
            root->child[str[0]] = get_node();
        }
        root = root->child[str[0]];
        ++str;
    }
    root->flag = 1;
    return 1;
}

void search(Trie *root, char *str, int k) {
    if (root == NULL) {
        return ;
    }
    if (root->flag) {
        str[k] = '\0';
        printf("%s\n", str);
    }
    for (int i = 0; i < 256; i++) {
        if (root->child[i] == NULL) continue;
        str[k] = i;
        search(root->child[i], str, k + 1);
    }
    return ;
}

int main() {
    char **str;
    str = (char **)malloc(sizeof(char *) * 12);
    for (int i = 0; i < 10; i++) {
        str[i] = (char *)malloc(sizeof(char) * 30);
    }
    Trie *root = get_node();
    for (int i = 0; i < 10; i++) {
        scanf("%s", str[i]);
        insert(root, str[i]);
    }
    char *temp;
    temp = (char *)malloc(sizeof(char));
    search(root, temp, 0);
    return 0;
}