/*************************************************************************
	> File Name: test64.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月17日 星期三 23时32分32秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

bool is_value(char *s, int *i, int d) {
    bool flag = true;
    int j = d;
    printf("in %d\n", *i);
    while (s[*i] && flag) {
        switch (s[*i]) {
            case '(': {
                ++(*i);
                flag = is_value(s, i, d + 1);
                if (s[*i] == ')') {
                    flag &= true;
                    ++(*i);
                } else {
                    return false;
                }
                break;
            }
            case '[': {
                ++(*i);
                flag = is_value(s, i, d + 1);
                if (s[*i] == ']') {
                    flag &= true;
                    ++(*i);
                } else {
                    return false;
                }
                break;
            }
            case '{': {
                ++(*i);
                flag = is_value(s, i, d + 1);
                if (s[*i] == '}') {
                    ++(*i);
                    flag &= true;
                } else {
                    return false;
                }
                break;
            }
            case ')': {
                
            }
            case ']': {

            }
            case '}': {
                return j == 0 ? false : true && flag;
            }
            default : break;
        }
    }
    return flag;
}

bool value(char *s) {
    int i = 0, len = strlen(s);
    bool flag = true;
    while (i < len && flag) {
        flag &= is_value(s, &i, 0);
    }
    return flag;
}

int main() {
    char s[100];
    while (~scanf("%s", s)) {
        printf("%d\n", value(s));
    }
}
