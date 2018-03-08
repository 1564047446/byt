/*************************************************************************
	> File Name: test93.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月26日 星期五 16时14分48秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    char c;
    scanf("%[^\n]s", s);
    getchar();
    scanf("%c", &c);
    printf("%d\n", strchr(s, c));
}
