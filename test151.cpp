#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int arr[100005];
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++) {
			scanf("%d", arr + i);
		}
		//sort(a, a + n);
		int minn = 0x3f3f3f3f, maxn = -1000000;
		for (int i = 0; i < n - 1;  i += 2) {
			minn = min(minn, arr[i] - arr[i + 1]);
			maxn = max(maxn, arr[i] + arr[i + 1]);
		}
		int ans_min = 0, ans_max = 0;
		for (int i = 0; i < n - 1; i += 2) {
			if (arr[i] - arr[i + 1] == minn) {
				ans_min++;
			}
			if (arr[i] + arr[i + 1] == maxn) {
				ans_max++;
			}
		}
		printf("%d %d\n", ans_min, ans_max);
	}
}