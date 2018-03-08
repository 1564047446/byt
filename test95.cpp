#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void radix_sort(int *num, int n) {
	#define maxn_n 65535
	int *cnt = (int *)calloc((maxn_n + 1), sizeof(int));
	int *temp = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		printf("num[%d] & 65536 = %d\n", i, num[i] & 65535);
		cnt[(num[i] & 65535) + 1] += 1;
		//printf("cnt[(num[i] & 65535) + 1] = %d\n", cnt[(num[i] & 65535)]);
	}
	for (int i = 1; i <= 65535; i++) {
		cnt[i] += cnt[i - 1];
		printf("cnt[%d] = %d\n", i, cnt[i]);
	}
	for (int i = 0; i < n; i++) {  // very important
		temp[cnt[num[i] & 65535]++] = num[i];
		printf("temp[cnt[num[i] & 65535]++] = %d\n", temp[cnt[num[i] & 65535]]);
	}
	memset(cnt, 0, sizeof(int) * maxn_n + 1);
	int *p = temp;
	temp = num;
	num = p;
	for (int i = 0; i < n; i++) {
		cnt[((num[i] >> 16) & 65535) + 1] += 1;
	}
	for (int i = 1; i <= 65535; i++) {
		cnt[i] += cnt[i - 1];
	}
	for (int i = 0; i < n; i++) {  // very important
		temp[cnt[(num[i] >> 16) & 65535]++] = num[i];
	}
	#undef maxn_n
	return ;
}

int main() {
	int n;
	scanf("%d", &n);
	int num[100];
	for (int i = 0; i < n; i++) {
		scanf("%d", num + i);
	}
	radix_sort(num, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", num[i]);
	}
	printf("\n");
	return 0;
}