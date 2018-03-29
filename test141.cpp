#include <stdio.h>
#include <string.h>

int main() {
	int a, b;
	int cnt = 0;
	scanf("%d%d", &a, &b);
	if (a % 3 == 2) {
		--a;
	}
	else if (a % 3 == 0) {
		a -= 2;
		cnt--;
	}
	if (b % 3 == 2) {
		b++;
		cnt++;
	}
	else if (b % 3 == 0) {
		b -= 2;
		cnt += 2;
	}
	cnt += ((b - a) / 3 * 2);
	printf("%d\n", cnt);
}