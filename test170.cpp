#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	char str[10000];
	scanf("%s", str);
	int i = 0, len = strlen(str);
	while (str[i] != '=') ++i;
	int num[10000], x[1000];
	int index = i + 1, cnt_1 = 0, cnt_2 = 0;
	int flag = 0, flag2 = 0;
	for (int i = 0; i < len; i++) {
		switch (str[i]) {
			case '+': {
				flag = 0;
				break;
			}
			case '-': {
				flag = 1;
				break;
			}
			case '=': {
				flag = 2;
				flag2 = 1;
				break;
			}
			default : {
				flag = 3;
				break;
			}
		}
		if (flag2 == 0) {
			if (flag == 0) {
				int temp = 0;
				++i;
				while (i < len && i >= '0' && i <= '9') {
					temp = temp * 10 + str[i] - '0';
					++i;
				}
				if (str[i] >= 'a' && str[i] <= 'z') {
					if (temp == 0) {
						x[cnt_2++] = 1;
					} else {
						x[cnt_2++] = temp;
					}
				} else {
					num[cnt_1++] = -temp;
					--i;
				}
			} else if (flag == 1) {
				int temp = 0;
				++i;
				while (i < len && i >= '0' && i <= '9') {
					temp = temp * 10 + str[i] - '0';
					++i;
				}
				if (str[i] >= 'a' && str[i] <= 'z') {
					if (temp == 0) {
						x[cnt_2++] = -1;
					} else {
						x[cnt_2++] = -temp;
					}
				} else {
					num[cnt_1++] = temp;
					--i;
				}
			} else if (flag == 3) {
				int temp = 0;
				while (i < len && i >= '0' && i <= '9') {
					temp = temp * 10 + str[i] - '0';
					++i;
				}
				if (str[i] >= 'a' && str[i] <= 'z') {
					if (temp == 0) {
						x[cnt_2++] = 1;
					} else {
						x[cnt_2++] = temp;
					}
				} else {
					num[cnt_1++] = -temp;
					--i;
				}
			}
		} else {
			if (flag == 0) {
				int temp = 0;
				++i;
				while (i < len && i >= '0' && i <= '9') {
					temp = temp * 10 + str[i] - '0';
					++i;
				}
				if (str[i] >= 'a' && str[i] <= 'z') {
					if (temp == 0) {
						x[cnt_2++] = 1;
					} else {
						x[cnt_2++] = temp;
					}
				} else {
					num[cnt_1++] = -temp;
					--i;
				}
			} else if (flag == 1) {
				int temp = 0;
				++i;
				while (i < len && i >= '0' && i <= '9') {
					temp = temp * 10 + str[i] - '0';
					++i;
				}
				if (str[i] >= 'a' && str[i] <= 'z') {
					if (temp == 0) {
						x[cnt_2++] = -1;
					} else {
						x[cnt_2++] = -temp;
					}
				} else {
					num[cnt_1++] = temp;
					--i;
				}
			} else if (flag == 3) {
				int temp = 0;
				while (i < len && i >= '0' && i <= '9') {
					temp = temp * 10 + str[i] - '0';
					++i;
				}
				if (str[i] >= 'a' && str[i] <= 'z') {
					if (temp == 0) {
						x[cnt_2++] = 1;
					} else {
						x[cnt_2++] = temp;
					}
				} else {
					num[cnt_1++] = -temp;
					--i;
				}
			}
		}
	}
	for (i = 0; i < cnt_1; i++) {
		printf("%d ", num[i]);
	}
	printf("\n");
	for (int j = 0; j < cnt_2; j++) {
		printf("%d ", x[j]);
	}
	printf("\n");
	return 0;
}