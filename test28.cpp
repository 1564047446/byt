/*************************************************************************
	> File Name: test28.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月05日 星期二 17时28分25秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#define inf 0x3f3f3f3f
#define mod 9973

int power(int a, int b) {
    int ans = 1, temp = a;
    while (b > 0) {
        if (b & 1) ans = (temp * ans) % mod;
        temp = (temp * temp);
        temp %= mod;
        b >>= 1;
    }
    return ans;
}

int cal(const char *string, int l, int r, int a_value) {
    int cur_min = -1, p = inf, temp_p = 0;
    for (int i = l; i < r; i++) {
        int cur_temp_p = inf + 1;
        switch (string[i]) {
            case '(': temp_p += 100; break;
            case ')': temp_p -= 100; break; 
            case '+': cur_temp_p = temp_p + 1; break;
            case '-': cur_temp_p = temp_p + 1; break;
            case '*': cur_temp_p = temp_p + 2; break;
            case '^': cur_temp_p = temp_p + 3; break;
        }
        if(cur_temp_p <= p) {
            cur_min = i;
            p = cur_temp_p;
        }
    }
    if(cur_min == -1) {
        int i = l;
        int num = 0;
        while(string[i] == ' ' || string[i] == '(') i++;
        if(string[i] == 'a') return a_value;
        sscanf(string + i, "%d", &num);
        return ((num % mod) + mod) % mod;
        } else {
            int a = cal(string, l, cur_min, a_value);
            int b = cal(string, cur_min + 1, r, a_value);
            int c;
            switch (string[cur_min]) {
                case '+': c = (a + b) % mod; break;
                case '-': c = (a - b) % mod; break;
                case '*': c = (a * b) % mod; break;
                case '^': c = power(a, b); break;
            }
            return (c + mod) % mod;
        }
    return 0;
}


int is_value(const char *stringq, const char *stringw) {
    for(int i = 1; i <= 200; i++) {
        int a = cal(stringq, 0, strlen(stringq), i);
        int b = cal(stringw, 0, strlen(stringw), i);
        if(a != b) return 0;
    }
    return 1;
}

int main() {
    char string[520], string2[520];
    while (scanf("%[^\n]s", string) != EOF) {
        int n;
        scanf("%d", &n);
        getchar();
        for (int i = 0; i < n; i++) {
            scanf("%[^\n]s", string2);
            getchar();
            if (is_value(string, string2)) printf("%c", i + 'A');
            //printf("%d\n", i);
        }
        printf("\n");
    } 
    return 0;
}
