#include <cstring>
#include <cstdio>

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	char str[1000][1000];
	for (int i = 0; i < n; i++) {
		scanf("%s", str[i]);
	}
	for (int i = 0; i < m; i++) {
		char temp[1000];
		scanf("%s", temp);
		int flag = 1;
		for (int j = 0; j < n; j++) {
			for (int k = 0; str[j][k]; k++) {
				if (str[j][k] != temp[k]) {
					flag = 0;
					break;
				}
			}
			if (flag) break;
		}
		if (flag) {
			printf("1\n");
		} else {
			printf("-1\n");
		}
	}
}