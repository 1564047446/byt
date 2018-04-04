#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n, maxn = 0;
    scanf("%d", &n);
    int hight[1005], node[1005], child[1005];
    memset(hight, 0, sizeof(hight));
    memset(node, 0, sizeof(node));
    memset(child, 0, sizeof(child));
    hight[0] = 1;
    node[0] = 1;
    for (int i = 0; i < n - 1; i++) {
        int node1, node2;
        scanf("%d%d", &node1, &node2);
        if (node[node1] == 0 || child[node1] == 2) continue;
        ++child[node1];
    	node[node2] = node[node1] + 1;
    	maxn = node[node2] > maxn ? node[node2] : maxn;
    }
    printf("%d\n", maxn);
}