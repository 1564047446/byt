#include <stdio.h>

long long arr[100][100][100];

long long w(long long a, long long b, long long c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	else if (a > 20 || b > 20 || c > 20) {
		return w(20, 20, 20);
	} else if (arr[a][b][c] == 0) {
		if (a < b && b < c) {
			arr[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		} else {
			arr[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
		}
		return arr[a][b][c];
	}
}

int main() {
	long long a, b, c;
	while (~scanf("%lld%lld%lld", &a, &b, &c)) {
		if (a == -1 && b == -1 && c == -1) break;
		printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, w(a, b, c));
	}
	return 0;
}