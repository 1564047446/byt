#include <stdio.h>

int a[10001];

int is_prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) return 0;
	}
	return 1;
}

int dfs(int left, int temp_sum, int l, int r) {
	if (left == 0) {
		return is_prime(temp_sum);
	}
	int sum = 0;
	for (int i = l; i <= r; i++) {
		sum += dfs(left - 1, temp_sum + a[i], i + 1, r);
	}
	return sum;
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	int ans = dfs(k, 0, 0, n - 1);
	printf("%d\n", ans);
}