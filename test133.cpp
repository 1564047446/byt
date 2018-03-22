#include <stdio.h>

int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_year(int x) {
	if (x % 400 == 0 || (x % 4 == 0 && x % 100 != 0)) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	int y = 2015, m = 10, d = 18;
	int year, mon, day, cnt = 0;
	scanf("%d-%d-%d", &year, &mon, &day);
	int flag1 = 1, flag2 = 1, flag3 = 1;
	for (int i = y; i <= year ; i++) {
		if (is_year(i)) months[1] += 1, flag2 = 0;
		if (flag1) {
			flag1 = 0;
			for (int j = m; j < 13; j++) {
				if (flag3 == 0) {
					for (int k = 1; k <= months[j - 1]; k++) {
						++cnt;
						if (i == year && j == mon && k == day) {
							printf("%d\n", cnt - 1);
							return 0;
						}
					}
					continue;
				}
				for (int k = d; k <= months[j - 1]; k++) {
					cnt++;
					if (i == year && j == mon && k == day) {
						printf("%d\n", cnt - 1);
						return 0;
					}
				}
				flag3 = 0;
			}
		} else {
			for (int j = 0; j < 12; j++) {
				for (int k = 1; k <= months[j]; k++) {
					cnt++;
					if (i == year && j + 1 == mon && k == day) {
						printf("%d\n", cnt - 1);
						return 0;
					}
				}
			}
		}
		if (flag2 == 0) {
			flag2 = 1;
			months[1] -= 1;
		}
	}
	return 0;
}

	
	//通过数学递推式， sum=（x+n-1）*((n/(n-1))^n) -n+1;其中x为最后一个熊分完后剩余的苹果数目
	//故x+n-1是(n-1)^n的整数倍。最小为1倍，即x+n-1=(n-1)^n.
	//故sum=n^n-n+1;