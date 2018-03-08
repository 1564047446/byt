/*************************************************************************
	> File Name: test65.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月18日 星期四 16时00分55秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#define inf 0x3f3f3f3f

int cal(const char *s, int left, int right) {
    int cur_pos = -1, temp_prio = 0, prio = inf;
    for (int i = left; i < right; i++) {
        int cur_prio = inf + 1;
        switch (s[i]) {
            case '(': temp_prio += 100; break;
            case ')': temp_prio -= 100; break;
            case '+': cur_prio = temp_prio + 1; break;
            case '-': cur_prio = temp_prio + 1; break;
            case '*': cur_prio = temp_prio + 2;
            case '/': cur_prio = temp_prio + 2; break;
        }
        if (cur_prio <= prio) {
            prio = cur_prio;
            cur_pos = i;
        }
    }
    if (cur_pos == -1) {
        int num = 0;
        for (int i = left; i < right; i++) {
            if (s[i] > '9' || s[i] < '0') continue;
            num = num * 10 + s[i] - '0';
        }
        return num;
    }
    int a = cal(s, left, cur_pos);
    int b = cal(s, cur_pos + 1, right);
    switch (s[cur_pos]) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}


int main() {
    char s[100];
    while (~scanf("%[^\n]s", s)) {
        getchar();
        printf("%s = %d\n", s, cal(s, 0, strlen(s)));
    }
}
