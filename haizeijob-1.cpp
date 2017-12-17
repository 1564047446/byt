/*************************************************************************
	> File Name: haizeijob-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月04日 星期一 12时27分57秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>


char string[1001];
int a[26] = {0};

int main() {
    int maxn = 0;
    while(~scanf("%s", string)) {
        for(int i = 0; i < strlen(string); i++) {
            if(string[i] >= 'A' && string[i] <= 'Z') {
                a[string[i] - 'A'] += 1;
                maxn = maxn > a[string[i] - 'A'] ? maxn : a[string[i] - 'A'];
            }
        }
    }
    int maxn2 = maxn;
    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < 26; j++) {
            if(a[j] == maxn2) {
                a[j]--;
                printf("* ");
            } else {
                printf("  ");
            }
        }
        maxn2--;
        printf("\n");
    }
    for(char i = 'A'; i <= 'Z'; i++) {
        printf("%c ", i);
    }
    printf("\n");
}
