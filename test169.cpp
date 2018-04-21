#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int sum = 1, row = 1, col = 1, i = 1;
	int flag1 = 1, flag2 = 0, flag3 = 0, flag4 = 0;
	while (sum < n) {
		if (flag1 && row == 1) {
			col++;
			flag1 = 0, flag2 = 1;
			sum++;
		} else if (flag2 && col != 1) {
			while (col != 1 && sum < n) {
				col--, row++;
				sum++;
			}
			flag2 = 0, flag3 = 1;
		} else if (flag3 && col == 1) {
			row++;
			flag3 = 0, flag4 = 1;
			sum++;
		} else if (flag4 && row != 1) {
			while (row != 1 && sum < n) {
				row--, col++;
				sum++;
			}
			flag4 = 0, flag1 = 1;
		}
	}
	printf("%d/%d\n", row, col);
	return 0;
}