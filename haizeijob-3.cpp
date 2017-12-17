/*************************************************************************
	> File Name: haizeijob-3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月04日 星期一 13时26分24秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#define inf 0x3f3f3f3f


double cal(const char *string, int l, int r) {
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
        }
        if(cur_prio <= priority) {
            cur_min = i;
            priority = cur_prio;
        }
    }
    if(cur_min == -1) {
        double num = 0;
        while(string[l] == ' ' || string[l] == '(') l++;
        sscanf(string + l, "%lf", &num);
        return num;
             } else {
                 double a = cal(string, l, cur_min);
                 double b = cal(string, cur_min + 1, r);
                 switch(string[cur_min]) {
                     case '+': return a + b;
                     case '-': return a - b;
                     case '*': return a * b;
                     case '/': return a / b;
                     }
                }
}






int main() {
    char string[205];
    while(~scanf("%[^\n]s", string)) {
        if(strcmp(string, "0") == 0) break;
        getchar();
        printf("%.2lf\n", cal(string, 0, strlen(string)));
    }
    return 0;
}
