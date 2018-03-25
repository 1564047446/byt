#include <stdio.h>

int is_par(long long x) {
    long long temp = 0, ans = x;
    while (x) {
        temp = temp * 10 + x % 10;
        x /= 10;
    }
    return x == ans;
}
int arr[2000000] = {0};
int main() {
    long long a, b;
    scanf("%lld%lld", &a, &b);
    for (int i = 2; i <= b; i++) {
        if (arr[i] == 0) {
            arr[i] = 1;
            arr[++arr[0]] = i;
        }
        for (int j = 1; j <= arr[0]; ++j) {
            if (i * arr[j] > b) break;
            if (i % arr[j]) {
                arr[j * i] = 1;
            } else {
                arr[j * i] = 1;
                break;
            }
        }
        for (int i = 1; i <= arr[0]; i++) {
            printf("%d\n", arr[i]);
        }
    }
}