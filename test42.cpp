/*************************************************************************
	> File Name: test42.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月25日 星期一 20时32分11秒
 ************************************************************************/

#include<iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

char s[1000];
char c[1000];
int main () {
    int maxn = 0;
    while (~scanf("%[^\n]s", s)) {
        getchar();
        if (strlen(s) > maxn) {
            maxn = strlen(s);
            strcpy(c, s);
        }
    }
    cout << "name is " << c << "\n" << "maxn = " << maxn << endl;
}
