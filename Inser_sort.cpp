/*************************************************************************
	> File Name: Inser_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月01日 星期五 16时29分36秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
int a[100] = {0};

using namespace std;


int main() {
    for(int i = 1; i < 10; i++) {
        scanf("%d", a + i);
    }
    for(int i = 2; i < 10; i++) {
        int key = a[i];
        int j = i - 1;
        while(j > 0 && a[j] > key) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
    }
    for(int i = 1; i < 10; i++) {
        printf("%d ", a[i]);
    }
    cout << endl;
}
