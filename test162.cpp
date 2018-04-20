#include <stdio.h>

int is_number(int a, int b, int c) {
	if (a > 1000 || b > 1000 || c > 1000) return 0;
	int arr[10];
	for (int i = 0; i < 10; i++) arr[i] = 0;
	while (a) {
		int temp = a % 10;
		if (temp == 0) return 0;
		if (arr[temp] == 1) return 0;
		arr[temp] = 1;
		a /= 10;
	}
	while (b) {
		int temp = b % 10;
		if (temp == 0) return 0;
		if (arr[temp] == 1) return 0;
		arr[temp] = 1;
		b /= 10;
	}
	while (c) {
		int temp = c % 10;
		if (temp == 0) return 0;
		if (arr[temp] == 1) return 0;
		arr[temp] = 1;
		c /= 10;
	}
	return 1;
}

int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int flag = 0;
	for (int i = 100; i < 1000; i++) {
		if (i % a) continue;
		int k = i / a;
		if (is_number(i, k * b, k * c)) {
			printf("%d %d %d\n", i, k * b, k * c);
			flag = 1;
		}
	}
	if (flag == 0) {
		printf("No!!!\n");
	}
	return 0;
}