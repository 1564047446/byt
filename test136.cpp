#include <stdio.h>
#include <string.h>

int main() {
	int flag[10], temp[10];
	for (int i = 0; i < 10; i++) flag[i] = 0;
	char str[1005];
	scanf("%s", str);
	int p;
	for (int i = 0; str[i]; i++) {
		flag[str[i] - '0']++;
		temp[str[i] - '0']++;
	}
	for (int i = 1; i <= 65535; i++) {
		int q = i;
		while (q) {
			int p = q % 10;
			if (flag[p] == 0) {
				printf("%d\n", i);
				return 0;
			} else {
				flag[p]--;
			}
			q = q / 10;
		}
		for (int i = 0; i < 10; i++) {
			flag[i] = temp[i];
		}
	}
	if (p == 0) {
		printf("10\n");
	} else printf("%d\n", p);
}