/*************************************************************************
	> File Name: test61.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月17日 星期三 15时41分15秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#define inf 0x3f3f3f3f

int get_value(const char *s, int left, int right) {
    int pori = inf, cur = -1, temp_pori = 0;
    for (int i = left; i < right; i++) {
        int cur_pro = inf + 1;
        switch (s[i]) {
            case '+': cur_pro = temp_pori + 1; break;
            case '-': cur_pro = temp_pori + 1; break;
            case '*': cur_pro = temp_pori + 10; break;
            case '/': cur_pro = temp_pori + 10; break;
        }
        if (cur_pro <= pori) {
            pori = cur_pro;
            cur = i;
        }
    }
    if (cur == -1) {
        int num;
        sscanf(s + left, "%d", &num);
        return num;
    } else {
        int a = get_value(s, left, cur);
        int b = get_value(s, cur + 1, right);
        switch (s[cur]) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
        }
    }
}

int main() {
    char s[23];
    scanf("%s", s);
    printf("%d\n", get_value(s, 0, strlen(s)));
}
