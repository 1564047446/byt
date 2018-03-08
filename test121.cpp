#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max_range 2000010
const int SIZE = 26;
const int MAX_LEN_T = 110005;
const int MAX_LEN_S = 2000005;
const char BASE = 'a';

void get_sort(char *buffer) {
	for (int i = 0; buffer[i]; i++) {
		for (int j = i + 1; buffer[j]; j++) {
			if (buffer[i] > buffer[j]) {
				char temp;
				temp = buffer[i];
				buffer[i] = buffer[j];
				buffer[j] = temp;
			}
		}
	}
}

int __ind(char ch) {
    if (ch <= BASE + 25 && ch >= BASE) {
        return ch - BASE + 1;
    } else {
        return 0;
    }
}
 
char __char(int num) {
    if (num <= 26 && num > 0) {
        return (char)(num + BASE - 1);
    } else {
        return '$';
    }
}

void get_t_origin(char *str) {
    char *o_str = (char *)malloc(MAX_LEN_T * sizeof(char));
    int *ind_arr = (int *)malloc(MAX_LEN_T * sizeof(int));
    int ch_num[27] = {0};
    int len = strlen(str);
    int i, j;
    for (i = 0; i < len; i++) {
        ch_num[__ind(str[i])]++;
    }
    for (j = 0, i = 0; i < 27; i++) {
        while (ch_num[i] > 0) {
            o_str[j++] = __char(i);
            ch_num[i]--;
        }
    }
    for (int i = 0; i < len; i++) {
        j = __ind(o_str[i]);
        while (str[ch_num[j]++] != o_str[i]) ;
        ind_arr[i] = ch_num[j] - 1;
    }
    j = ind_arr[0];
    i = 0;
    while (j) {
        str[i++] = o_str[j];
        j = ind_arr[j];
    }
    str[i] = '\0';
    free(o_str);
    free(ind_arr);
    return ;
}

void get_next(char *pattern, int *next) {
	next[0] = -1;
	int i = 1, j = -1;
	for (; pattern[i]; i++) {
		while (j > -1 && pattern[i] != pattern[j + 1]) j = next[j];
		if (pattern[i] == pattern[j + 1]) ++j;
		next[i] = j;
	}
}

int kmp(char *org, char *pattern) {
	int len = strlen(pattern);
	int next[len];
	get_next(pattern, next);
	int i = 0, j = -1;
	for (; org[i]; i++) {
		while (j > -1 && org[i] != pattern[j + 1]) j = next[j];
		if (org[i] == pattern[j + 1]) ++j;
		if (j == len - 1) return 1;
	}
	return 0;
}

int main() {
	char buffer[max_range], str[max_range], org[max_range], pattern[max_range];
	scanf("%s", str);
	strcpy(buffer, str);
	get_sort(buffer);
	//printf("buffer : %s\n", buffer);
	get_t_origin(str);
	//printf("org : %s\n", org);
	int m;
	scanf("%d", &m);
	while (m--) {
		scanf("%s", pattern);
		int ans = kmp(str, pattern);
		if (ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}