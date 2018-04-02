/*************************************************************************
	> File Name: test147.cpp
	> Author:  byt 
	> Mail: baotongyu1995@163.com
	> Created Time: 2018年03月31日 星期六 17时42分16秒
 ************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

int used[10001] = {0};
int arr[1001] = {0};

void print(int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void dfs(int depth, int n) {
    if (depth >= n) {
        print(n);
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (used[i] == 0) {
            used[i] = 1;
            arr[depth] = i;
            dfs(depth + 1, n);
            used[i] = 0;
        }
    }
    return ;
}

int main() {
    dfs(0, 4);
    return 0;
}
