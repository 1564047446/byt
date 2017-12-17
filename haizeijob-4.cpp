/*************************************************************************
	> File Name: haizeijob-4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月04日 星期一 14时18分55秒
 ************************************************************************/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int mod = 9973;

#define inf 0x3f3f3f3f

int power(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}


int cal(const char *string, int l, int r, int a_value) {
    int cur_min = -1, priority = inf, temp_prio = 0;
    for(int i = l; i < r; i++) {
        int cur_prio = inf + 1;
        switch(string[i]) {
            case '(': temp_prio += 100; break;
            case ')': temp_prio -= 100; break;
            case '+':
            case '-': cur_prio = temp_prio + 1; break;
            case '*':
            case '/': cur_prio = temp_prio + 2; break;
            case '^': cur_prio = temp_prio + 3; break;
        }
        if(cur_prio <= priority) {
            cur_min = i;
            priority = cur_prio;
        }
    }
    if(cur_min == -1) {
        int num = 0, i = l;
        while(string[i] == ' ' || string[i] == '(') i++;
        if(string[i] == 'a') return a_value;
        sscanf(string + i, "%d", &num);
        return num;
             } else {
                 int a = cal(string, l, cur_min, a_value);
                 int b = cal(string, cur_min + 1, r, a_value);
                 int c;
                 switch(string[cur_min]) {
                     case '+': c = ((a + b)) % mod; break;
                     case '-': c = ((a - b)) % mod; break;
                     case '*': c = ((a * b) % mod); break;
                     case '/': return a / b;
                     case '^':c = power(a, b) % mod; break;     
                     }
                 return (c + mod) % mod;
                }
    return 0;
}

int is_value(const char *string, const char *string2) {
    for(int i = 1; i <= 100; i++) {
        int a = cal(string, 0, strlen(string), i);
        int b = cal(string2, 0, strlen(string2), i);
        if(a != b) return 0;
    }
    return 1;
}




int main() {
    char string[205];
    scanf("%[^\n]s", string);
    getchar();
    int n;
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < strlen(string); i++) {
        if(string[i] == 'a') string[i] = '1';
    }
    int num = 0;
    while(n--) {
        char string2[400];
        scanf("%[^\n]s", string2);
        getchar();
        num++;
        if(is_value(string, string2)) printf("%c", num + 'A' - 1);
    }
    return 0;
}
