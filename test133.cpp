#include <stdio.h>

int main() {
	int sum = 0;
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("a = %d, b = %d\n", a, b);
		sum = sum + b - a;
	}
	printf("%d\n", sum);
	return 0;
}