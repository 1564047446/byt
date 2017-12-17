/*************************************************************************
	> File Name: test24.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月03日 星期日 18时42分11秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>


char string1[1001];
char string2[1001];
char string3[1001];
char string4[1001];

int a[256] = {0};
char string[100][100];
int main() {
    
    int maxn = 0
    while(scanf("%s", string1) != EOF) {
        for(int i = 0; i < strlen(string1); i++) {
            a[string1[i] - 'A'] += 1;
            maxn = maxn > a[string[i] - 'A'] ? maxn : a[string1[i] - 'A'];
        }
    }
    for(int i = maxn; i > 0; i--) {
        for(int j = 0; j < 26; j++) {
            if(a[j] != 0) {
                printf("* ");
                a[j]--;
            } else {
                printf("  ");
            }
    }}
    return 0;
}
