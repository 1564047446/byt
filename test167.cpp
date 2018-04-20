#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void pre_reserve(char *str, int l, int r) {
	int head = 1;
	while (l != r) {
        if (str[r] == '0' && head == 1) --r;
		else {
			head = 0;
			printf("%c", str[r]);
			--r;
		}
	}
	if (head == 1) printf("0");
	return ;
}

void back_reserve(char *str, int l, int r) {
	int tail = 1, head = 1, cnt = 0;
	char *buffer = (char *)malloc(sizeof(char) * 30);
	while (l != r) {
		if (head == 1 && str[l] == '0') ++l;
		else {
			head = 0;
			buffer[cnt++] = str[l];
			++l;
		}
	}
	if (head == 1) {
		printf("0");
		return ;
	}
	buffer[cnt] = '\0';
	pre_reserve(buffer, -1, cnt - 1);
	printf("\n");
	return ;
}


int main() {
	char num[100], cur;
	int index = -1;
	scanf("%s", num);
	int len = strlen(num);
	for (int i = 0; num[i]; ++i) {
		if (num[i] >= '0' && num[i] <= '9') {
			continue;
		}
		index = i;
		cur = num[i];
		break;
	}
	if (index == -1) {
		pre_reserve(num, -1, len - 1);
	} else {
		switch (cur) {
			case '.': {
				pre_reserve(num, -1, index - 1);
				printf(".");
				back_reserve(num, index + 1, len);
				break;
			}
			case '%': {
				pre_reserve(num, -1, index - 1);
				printf("%c", cur);
				printf("\n");
				break;
			}
			case '/': {
				pre_reserve(num, -1, index - 1);
				printf("/");
				back_reserve(num, index + 1, len);
				break;
			}
		}
	}
}
