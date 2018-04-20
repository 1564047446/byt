#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	if (n < 10 || n > 30) {
		printf("0\n");
		return 0;
	}
	int temp[10000][10];
	int ans = 0;
	for (int a1 = 1; a1 <= 3; a1++) {
		for (int a2 = 1; a2 <= 3; a2++) {
			for (int a3 = 1; a3 <= 3; a3++) {
				for (int a4 = 1; a4 <= 3; a4++) {
					for (int a5 = 1; a5 <= 3; a5++) {
						for (int a6 = 1; a6 <= 3; a6++) {
							for (int a7 = 1; a7 <= 3; a7++) {
								for (int a8 = 1; a8 <= 3; a8++) {
									for (int a9 = 1; a9 <= 3; a9++) {
										for (int a10 = 1; a10 <= 3; a10++) {
											if (a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 == n) {
												temp[ans][0] = a1, temp[ans][1] = a2;
												temp[ans][2] = a3, temp[ans][3] = a4;
												temp[ans][4] = a5, temp[ans][5] = a6;
												temp[ans][6] = a7, temp[ans][7] = a8;
												temp[ans][8] = a9, temp[ans][9] = a10;
												++ans;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	for (int i = 0; i < ans; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				printf("%d", temp[i][j]);
			} else {
				printf(" %d", temp[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}