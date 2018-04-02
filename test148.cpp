#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int map[401][401], visited[405];
int bfs(int start, int end, int n) {
    int queue[500];
    int head = 0, tail = 0;
    queue[tail++] = start;
    while (head < tail) {
        int temp = queue[head++];
        for (int i = 1; i <= n; i++) {
            if (map[temp][i] && visited[i] == 0) {
                visited[i] = 1;
                queue[tail++] = i;
            }
            if (i == end) {
                return 1;
            }
        }
    }
    return 0;
}


int main() {
    
    int n , m, day;
    while (~scnf("%d%d%d", &n, &m, &day)) {
        if (n == 0 && m == 0 && day == 0) break;
        char string[21][21];
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++) {
            scanf("%s", string[i]);
        }
        int start = 0, cnt = 0, end = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ++cnt;
                if (str[i][j] == 'S') start = cnt;
                if (str[i][j] == 'P') end = cnt;
                if (str[i][j] == '*') continue;
                if (j + 1 < m && str[i][j + 1]) {
                    map[cnt][cnt + 1] = map[cnt + 1][cnt] = 1;
                }
                if (j - 1 >= 0 && str[i][j - 1] == '.') {
                    map[cnt][cnt - 1] = map[cnt - 1][cnt] = 1;
                }
                if (i + 1 < n && str[i + 1][j] == '.') {
                    map[cnt + m][cnt] = map[cnt][cnt + m] = 1;
                }
                if (i - 1 >= 0 && str[i - 1][j] == '.') {
                    map[cnt - m][cnt] = map[cnt][cnt - m] = 1;
                }
            }
        }
        int ans = bfs(start, end, cnt);
        if (ans) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }

    }
    return 0;
}