#include <stdio.h>

int main() {
    int n;
    char arr[1005];
    scanf("%d", &n);
    while (n--) {
        int len;
        scanf("%d", &len);
        scanf("%s", arr);
        int cnt = 0, ans = 0;
        int flag = 0;
        if (len == 1) {
            if (arr[0] == 'X') {
                printf("0\n");
                continue;
            } else {
                printf("1\n");
                continue;
            }
        }
        for (int i = 1; i < len; i++) {
            if (i + 1 == len && arr[i] == '.') {
                ++ans;
                break;
            }
            if (arr[i] == 'X') {
                int flag = 0, flag2 = 0;
                if (arr[i - 1] == '.') {
                    flag = 1;
                } 
                if (i + 1 < len && arr[i + 1] == '.') {
                    flag2 = 1;
                }
                if (flag && flag2 || flag) {
                    ++ans;
                    arr[i - 1] = arr[i + 1] = 'X';  
                }
            } else {
                int flag = 0, flag2 = 0;
                if (arr[i - 1] == '.') {
                    flag = 1;
                }
                if (i + 1 < len && arr[i + 1] == '.') {
                    flag2 = 1;
                }
                if (flag || flag && flag2) {
                    ++ans;
                    arr[i - 1] = arr[i + 1] = arr[i] = 'X';
                }
            }
        }
        printf("%d\n", ans);
    }
}