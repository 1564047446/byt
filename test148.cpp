#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int map[420][420], visited[420];
int bfs(int start, int end, int n) {
    int queue[500];
    int head = 0, tail = 0;
    int ans[500] = {0};
    ans[start] = 0;
    queue[tail++] = start;
    while (head < tail) {
        int temp = queue[head++];
        for (int i = 1; i <= n; i++) {
            if (map[temp][i] && visited[i] == 0) {
                visited[i] = 1;
                queue[tail++] = i;
                ans[i] = ans[temp] + 1;
                if (i == end) return ans[i];
            }
        }
    }
    return 0;
}


int main() {
    
    int n , m, day;
    while (~scanf("%d%d%d", &n, &m, &day)) {
        if (n == 0 && m == 0) break;
        char str[25][25];
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++) {
            scanf("%s", str[i]);
        }
        int start = -1, cnt = 0, end = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ++cnt;
                if (str[i][j] == 'S') start = cnt;
                if (str[i][j] == 'P') end = cnt;
                if (str[i][j] == '*') continue;
                if (j + 1 < m && (str[i][j + 1] == '.' || str[i][j + 1] == 'P' || str[i][j + 1] == 'S')) {
                    map[cnt][cnt + 1] = map[cnt + 1][cnt] = 1;
                }
                if (j - 1 >= 0 && (str[i][j - 1] == '.' || str[i][j - 1] == 'P' || str[i][j - 1] == 'S')) {
                    map[cnt][cnt - 1] = map[cnt - 1][cnt] = 1;
                }
                if (i + 1 < n && (str[i + 1][j] == '.' || str[i + 1][j] == 'P' || str[i + 1][j] == 'S')) {
                    map[cnt + m][cnt] = map[cnt][cnt + m] = 1;
                }
                if (i - 1 >= 0 && (str[i - 1][j] == '.' || str[i - 1][j] == 'P' || str[i - 1][j] == 'S')) {
                    map[cnt - m][cnt] = map[cnt][cnt - m] = 1;
                }
            }
        }
        //printf("%d %d %d")
        if (start != -1 && end != -1) {
            int ans = bfs(start, end, cnt);
            if (ans != 0 && ans <= day) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        } 

    }
    return 0;
}