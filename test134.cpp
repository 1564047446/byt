#include <stdio.h>

int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int get_mul(int x) {
	int sum = 1;
	for (int i = 1; i <= x; i++) sum *= i;
	return sum;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 10; i++) {
		int sum = get_mul(9 - i);
		if (sum > n) continue;
		int j = i + 1;
		while (n >= sum && j < 10) {
			int t = a[i], a[i] = a[j], a[j] = t;
			++j, n -= sum;
		}
	}
	for (int i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}