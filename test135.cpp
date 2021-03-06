#include <stdio.h>
#include <string.h>

int get_mul(int x) {
	int sum = 1;
	for (int i = 1; i <= x; i++) {
		sum *= i;
	}
	return sum;
}

int main() {
	int n;
	char str[15] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'};
	scanf("%d", &n);
	while (n--) {
		int ans = 1;
		char temp[15], test[15];
		strcpy(test, str);
		scanf("%s", temp);
		for (int i = 0; i < 12; i++) {
			if (temp[i] == test[i]) continue;
			int j = i + 1;
			while (temp[i] != test[i] && j < 12) {
				ans += get_mul(11 - i);
				char t = test[i];
				test[i] = test[j], test[j] = t;
				++j;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}