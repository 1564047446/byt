#include <stdio.h>

int main() {
	int sum = 0;
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		sum += b;
		sum -= a;
	}
	printf("%d\n", sum);
	return 0;
}