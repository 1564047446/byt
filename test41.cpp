/*************************************************************************
	> File Name: test41.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月22日 星期五 16时01分46秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>

using namespace std;



int main() {
    int n;
    scanf("%d", &n);
    while (n) {
        printf("%d", n % 2);
        n /= 2;
    }
}
