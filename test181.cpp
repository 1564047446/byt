/*************************************************************************
	> File Name: test181.cpp
	> Author:  byt 
	> Mail: baotongyu1995@163.com
	> Created Time: 2018年05月09日 星期三 16时55分26秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    char s1[100], s2[100];
    cin >> s1 >> s2;
    int arr[100] = {0}, brr[100] = {0};
    int len1 = strlen(s1), len2 = strlen(s2);
    for (int i = 0; i < len1; i++) {
        arr[len1 - i] = s1[i] - '0';
    }
    for (int i = 0; i < len2; i++) {
        brr[len2 - i] = s2[i] - '0';
    }
    int ans[100] = {0};
    int cnt = 0;
    for (int i = 1; i <= len1; i++) {
        cnt = i;
        for (int j = 1; j <= len2; j++) {
            ans[cnt] = arr[i] * brr[j] + ans[cnt];
            ++cnt;
        }
        for (int j = 1; j <= cnt; j++) {
            if (ans[j] < 10) continue;
            int temp = ans[j] / 10;
            ans[j + 1] += temp;
            ans[j] %= 10;
            if (j == cnt) ++cnt;
        }
    }
    for (int i = cnt; i >= 1; i--) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
