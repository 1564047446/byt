/*************************************************************************
	> File Name: test183.cpp
	> Author:  byt 
	> Mail: baotongyu1995@163.com
	> Created Time: 2018年05月09日 星期三 18时06分31秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    int x;
    //int arr[100000] = {0};
    //int ans[100000] = {0};
    while (~scanf("%d", &x)) {
        int *arr = (int *)malloc(sizeof(int) * 1000);
        int *ans = (int *)malloc(sizeof(int) * 1000);
        memset(arr, 0, sizeof(arr));
        memset(ans, 0, sizeof(ans));
        arr[0] = arr[1] = 1;
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= arr[0]; j++) {
                arr[j] *= i;
            }
            for (int j = 1; j <= arr[0]; j++) {
                if (arr[j] < 100) continue;
                arr[j + 1] += arr[j] / 100;
                arr[j] %= 100;
                if (j == arr[0]) ++arr[0];
            }
        }
        for (int i = arr[0]; i >= 1; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
        //aaaaa   
        ans[0] = ans[1] = 1;
        for (int i = arr[0]; i >= 1; i--) {
            while (arr[i]) {
                for (int j = 1; j <= ans[0]; j++) {
                    int temp = arr[i] % 10;
                    if (temp == 0) continue;
                    ans[j] *= temp;
                }
                for (int j = 1; j <= ans[0]; j++) {
                    if (ans[j] < 10) continue;
                    ans[j + 1] += ans[j] / 10;
                    ans[j] %= 10;
                    if (j == ans[0]) ++ans[0];
                }
                arr[i] /= 10;
            }
        }
        for (int i = ans[0]; i >= 1; i--) {
            cout << ans[i];
        }
        cout << endl;
        free(ans);
        free(arr);
    }
    return 0;
}