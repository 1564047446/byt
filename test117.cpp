#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void get_next(char *buffer, int *next) {
	next[0] = -1;
	int i = 1, j = -1;
	for (; buffer[i]; i++) {
		while (j != -1 && buffer[i] != buffer[j + 1]) {
			j = next[j];
		}
		if (buffer[i] == buffer[j + 1]) j++;
		next[i] = j;
	}
	return ;
}

int kmp(char *str, char *buffer, int *next) {
	int len2 = strlen(buffer), cnt = 0;
	int i = 0, j = -1;
	for (; str[i]; i++) {
		while (j != -1 && str[i] != buffer[j + 1]) j = next[j];
		if (str[i] == buffer[j + 1]) ++j;
		if (j + 1 == len2) ++cnt, j = -1;
	}
	return cnt;
}

int main() {
	int n;
	scanf("%d", &n);
	getchar();
	char str[n][30], buffer[100100];
	for (int i = 0; i < n; i++) {
		scanf("%[^\n]s", str[i]);
		getchar();
	}
	//getchar();
	scanf("%[^\n]s", buffer);
	getchar();
	int *next = (int *)malloc(sizeof(int) * strlen(buffer));
	get_next(buffer, next);
	for (int i = 0; i < n; i++) {
		if (strlen(str[i]) == 0) printf("%d: %d\n", i, 0);
		else printf("%d: %d\n", i, kmp(buffer, str[i], next));
	}
	return 0;
}