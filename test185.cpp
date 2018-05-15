#include <cstdio>
#include <cstring>
#include <cstdio>

int main() {
	char str[1000];
	int ans = 0;
	char queue[1000][1000];
	int row = 0, col = 0;
	while (~scanf("%[^\n]s", str)) {
		col = 0;
		getchar();
		//printf("%s\n", str);
		for (int i = 0; str[i]; ++i) {
			if (str[i] == '/' || str[i] == '*' || str[i] == '"') {
				queue[row][col++] = str[i];
			}
		}
	queue[row][col] = '\0';
	row++;	
	}
	int flag = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < queue[i][j]; j++) {
			if (flag == 1) {
				if (queue[i][j] == '"') {
					flag = 0;
				}
				continue;
			} else if (flag == 2) {
				if (queue[i][j] == '/') {
					ans++;
					flag = 100;
				}
				if (queue[i][j] == '*') {
					flag = 3;
				}
			} else if (flag == 3) {
				if (queue[i][j] == '*') {
					flag = 4;
				}
			} else if (flag == 4) {
				if (queue[i][j] == '/') {
					flag = 0;
					ans++;
				}
			} else if (flag == 0) {
				if (queue[i][j] == '"') {
					flag = 1;
				} else if (queue[i][j] == '/') {
					flag = 2;
				}
			}
		}
		if (flag == 100) flag = 0;
	}
	printf("%d\n", ans);
	return 0;
}