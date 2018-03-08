/*************************************************************************
	> File Name: test105.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年02月02日 星期五 15时41分42秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int find(char *buffer, char *pattern) {
    int len1 = strlen(buffer), len2 = strlen(pattern);
    for (int i = 0; i <= len1 - len2; ++i) {
        int j = 0;
        while (j < len2 && buffer[i + j] == pattern[j]) ++j;
        if (j == len2) return i;
    }
    return -1;
}

int main() {
    char buffer[100], pattern[100];
    while (~scanf("%s%s", buffer, pattern)) {
        int ans = find(buffer, pattern);
        printf("ans = %d\n", ans);
    }
    return 0;
}
