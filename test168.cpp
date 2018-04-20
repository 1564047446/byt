#include <stdio.h>

int main() {
	int n, i;
	scanf("%d", &n);
	int sum = 0, i;
	for (i = 1; ; i++) {
		if (sum + i >= n) break;
		sum += i;
	}
	if (i % 2 == 0) {
		if (sum == n) {
			a = 1, b = i;
		} else if (sum - n == 1) {
			
		}
	} else {

	}
	printf("%d/%d\n", a, b);
	return 0;
}