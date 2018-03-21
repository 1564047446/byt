#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int cnt = 0, day = 1, flag = 1, up = 0, down = 0;
	for (int i = 1; i <= n && flag; i++) {
		if (i == 1) continue;
		if (i % 2 == 0) {
			++up;
			for (int i = 1; i <= up; i++) {
				if (day == n) {
					flag = 0;
					break;
				}
				day++;
			}
		} else {
			++down;
			day++;
			if (day == n) {
				flag = 0;
				break;
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= up; i++) {
		sum += i;
	}
	printf("%d\n", sum - down);
}