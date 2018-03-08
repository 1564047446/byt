#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxn 1000010
int kmp2(char *, char *);
int kmp1(char *, char *, char *);
void get_next(char *, int *);   

void get_next(char *str, int *next) {
	int i = 0, j = -1;
	next[0] = -1;
	for (i = 1; str[i]; i++) {
		while (j != -1 && str[i] != str[j + 1]) j = next[j];
		if (str[i] == str[j + 1]) j++;
		next[i] = j;
	}
	return ;
}

int kmp1(char *str1, char *str2, char *buffer) {
    int len = strlen(buffer);
    int *next = (int *)malloc(sizeof(int) * len);
    get_next(buffer, next);
    int i = 0, j = -1;
    for (; str1[i]; i++) {
        while (j != -1 && buffer[j + 1] != str1[i]) j = next[j];
        if (str1[i] == buffer[j + 1]) ++j;
        if (j + 1 == len) {
            if (kmp2(str2, buffer) == i - j) return i - j;
            else j = -1;
            //return i - j;
        }
    }
    return -1;
}

int kmp2(char *str2, char *buffer) {
    int len = strlen(buffer);
    //printf("start : str2 = %s\n", str2);
    int *next = (int *)malloc(sizeof(int) * len);
    get_next(buffer, next);
    int i = 0, j = -1;
    for (; str2[i]; i++) {
        while (j != -1 && str2[i] != buffer[j + 1]) j = next[j];
        if (str2[i] == buffer[j + 1]) ++j;
        if (j + 1 == len) {
            //printf("kmp2 i - j = %d\n", i - j);
            return i - j;
        }
    }
    return -1;
}

int main() {
    char str1[maxn], str2[maxn], buffer[1100];
    scanf("%[^\n]s", str1);
    getchar();
    scanf("%[^\n]s", str2);
    getchar();
    scanf("%[^\n]s", buffer);
    getchar();
    if (kmp1(str1, str2, buffer) == -1) printf("0\n");
    else printf("%d\n", kmp1(str1, str2, buffer));
    return 0;
}
