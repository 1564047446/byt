#include <stdio.h>

#define pi 0.98

int main() {
	int s, x;
	scanf("%d%d", &s, &x);
	double dis = 0.0, start = 7.0, x1 = (double)(x), s1 = (double)(s);
	while (dis < s1 - x1) {
		dis += start;
		start *= pi;
	}
	if (dis + start * pi >= s1 + x1) {
		printf("n\n");
	} else {
		printf("y\n");
	}
	return 0;
}