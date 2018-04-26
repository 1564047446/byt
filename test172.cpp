#include <stdio.h>

int get_solution(int *arr, int n) {
	int sum = 0, ans = 0;
	for (int i = 0; i < 32; i++) {
		sum = 0;
		for (int j = 0; j < n; j++) {
			sum += ((arr[j] >> i) & 1);

		}
		if (sum % 3 == 1) {
			ans = ans | (1 << i);
		}
	}
	printf("%d\n", ans);
	return 0;
}


int main() {
	int arr[1000], n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}
	int a = 0;
	int ones = 0, tows = 0;
	for (int i = 0; i < n; i++) {
		ones = (~twos) & (ones ^ arr[i]);
		twos = (~ones) & (tows ^ arr[i]);
	}
	get_solution(arr, n);
	return 0;
}