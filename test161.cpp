#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

struct test {
	int x, y;
};

int cmp(test a, test b) {
	return a.y < b.y;
}

test temp[10000];

int main() {
	int n, s, a, b;
	scanf("%d%d", &n, &s);
	scanf("%d%d", &a, &b);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &temp[i].x, &temp[i].y);
	}
	sort(temp, temp + n, cmp);
	int ans = 0;
	int temp_s = s, i = 0;
	while (n--) {
		if (temp[i].x <= b + a && temp_s - temp[i].y >= 0) {
			//printf("x = %d, b + a = %d\n", temp[i].x, b + a);
			temp_s -= temp[i].y;
			++ans;
		}
		if (temp <= 0) break;
		++i;
	}
	printf("%d\n", ans);
	return 0;
}