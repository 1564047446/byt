/*************************************************************************
	> File Name: test27.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月05日 星期二 16时40分11秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#include <string.h>

#define inf 0x3f3f3f3f
#define mod 9973

int power_quick(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if (b & 1) a = (a * ans) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
}


int cal(const char *string, int l, int r) {
    int cur_min = -1, p = inf, temp_p = 0;
    for(int i = l; i < r; i++) {
        int cur_temp_p = inf + 1;
        switch (string[i]) {
            case '(': temp_p += 100; break;
            case ')': temp_p -= 100; break;
            case '+': cur_temp_p = temp_p + 1; break;
            case '-': cur_temp_p = temp_p + 1; break;
            case '*': cur_temp_p = temp_p + 2; break;
            case '/': cur_temp_p = temp_p + 2; break;
        }
        if (cur_temp_p <= p) {
            cur_min = i;
            p = cur_temp_p;
        }
    }
    printf("lalala\n");
    if (cur_min == -1) {
        int num = 0;
        while(string[l] == ' ' || string[l] == '(') l++;
        sscanf(string + l, "%d", &num);
        printf("num = %d\n", num);
        return num;
        } else {
            int a = cal(string, l, cur_min);
            int b = cal(string, cur_min + 1, r);
            switch (string[cur_min]) {
                case '+': return a + b;
                case '-': return a - b;
                case '*': return a * b;
                case '/': return a / b;
            }
        }
    return 0;
}



int main() {
    char string[200], string2[200];
    while(~scanf("%[^\n]s", string)) {
        getchar();
        if(strcmp(string, "0") == 0) break;
        printf("result = %d\n", cal(string, 0, strlen(string)));
    }
}


 
