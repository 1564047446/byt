#include <stdio.h>

int get_ans(int x) {
	int f[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	int ans = 0;
	if (x == 0) {
		return f[0];
	}
	while (x) {
		int k = x % 10;
		ans += f[k];
		x /= 10;
	}
	return ans;
}

int main() {
	int n, ans = 0;
	scanf("%d", &n);

	for (int i = 0; i <= 1111; i++) {
		for (int j = 0; j <= 1111; j++) {
			int c = i + j, a = i, b = j;
			if (get_ans(a) + get_ans(b) + get_ans(c) + 4 == n) {
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}