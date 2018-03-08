/*************************************************************************
	> File Name: test82.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月24日 星期三 19时50分49秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void get_num(int *num, char *str, int n) {
    if (n == 0) return ;
    str[(*num)++] = *(num) + '0';
    get_num(num, str, --n);
}


int main() {
    int num = 0;
    char *s = (char *)malloc(sizeof(char) * 100);
    get_num(&num, s, 2);
    printf("%s", s);
    return 0;
}
