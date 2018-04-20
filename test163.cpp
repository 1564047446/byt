#include <stdio.h>

#define maxn 20001

int main() {
	int prime[maxn] = {0};
	for (int i = 2; i < maxn; i++) {
		if (prime[i] == 0) {
			prime[++prime[0]] = i;
		}
		for (int j = 1; j <= prime[0]; j++) {
			if (i * prime[j] > maxn) break;
			prime[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= prime[0]; i++) {
		for (int j = 1; j <= prime[0]; j++) {
			for (int k = 1; k <= prime[0]; k++) {
				if (prime[i] + prime[j] + prime[k] == n) {
					printf("%d %d %d\n", prime[i], prime[j], prime[k]);
					return 0;
				}
			}
		}
	}
	return 0;
}