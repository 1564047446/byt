#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void get_temp(char *buffer, char *temp) {
	int i = 0, j = 0;
	while (buffer[i]) {
		if (buffer[i] <= 'z' && buffer[i] >= 'a') {
			temp[j++] = buffer[i++];
		} else {
			++i;
			int index1 = i, index2 = 0, flag = 1;
			while (flag) {
				if (buffer[i] >= 'a' && buffer[i] <= 'z') {
					temp[j++] = buffer[i++];
				} else {
					index2 = i;
					++i;
					int num = 0;
					while (1) {
						if (buffer[i] >= '0' && buffer[i] <= '9') {
							num = num * 10 + buffer[i] - '0';
						} else break;
						++i;
					}
					//printf("num = %d, index1 = %d, index2 = %d\n", num, index1, index2);
					for (int k = 0; k < num - 1; k++) {
						for (int ind1 = index1; ind1 < index2; ind1++) {
							temp[j++] = buffer[ind1];
						}
					}
					flag = 0;
				}
			}
		}
	}
	temp[j] = '\0';
}

void get_next(char *str, int *next) {
	int i = 1, j = -1;
	next[0] = -1;
	for (; str[i]; i++) {
		while (j > -1 && str[i] != str[j + 1]) j = next[j];
		if (str[i] == str[j + 1]) ++j;
		next[i] = j;
	}
}

int kmp(char *buffer, char *str) {
	int next[strlen(str)], ans = 0;
	get_next(str, next);
	int i = 0, j = -1;
	for (; buffer[i]; i++) {
		while (j > -1 && buffer[i] != str[j + 1]) j = next[j];
		if (buffer[i] == str[j + 1]) ++j;
		if (j + 1 == strlen(str)) ans++, j = -1;
	}
	return ans;
}

int main() {
	char buffer[1001], temp[10000000], str[1001];
	scanf("%s", buffer);
	scanf("%s", str);
	get_temp(buffer, temp);
	//printf("%s\n", temp);
	printf("%d\n", kmp(temp, str));
	return 0;
}