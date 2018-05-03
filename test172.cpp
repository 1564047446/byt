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

int getSum(int a, int b) {
    int p = a ^ b;
    int q = (a & b) << 1;
    while (q != 0) {
        p = p ^ q;
        q = (p & q) << 1;
    }
    return p | q;
}

3 + 2 

a 0 1 1
b 0 1 0

0 0 1
1 0 0
