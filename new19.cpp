#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn 1000

int prime[maxn + 1] = {0};
int num[maxn + 1] = {0};
int min_num[maxn + 1] = {0};

int main() {
	printf("hello world\n");
	printf("maxn = %d\n", maxn);
	for (int i = 2; i < maxn; i++) {
		if (prime[i] == 0) {
			prime[++prime[0]] = i;
			min_num[i] = 2;
			num[i] = 2;
		}
		for (int j = 1; j <= prime[0]; j++) {
			if (i * prime[j] > maxn) break;
			prime[i * prime[j]] = 1;
			if (i % prime[j]) {
				num[i * prime[j]] = num[i] * prime[j];
				min_num[i * prime[j]] = min_num[prime[j]];
			} else {
				num[i * prime[j]] = num[i] / (min_num[prime[j]]) * (min_num[prime[j]] + 1);
				min_num[i * prime[j]] = min_num[prime[j]] + 1;
				break;
			}
		}
	}
	int n;
	while (~scanf("%d", &n)) {
		printf("min_num = %d, num = %d\n", min_num[n], num[n]);
	}
	return 0;

}