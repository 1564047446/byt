/*************************************************************************
	> File Name: test29.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月07日 星期四 11时28分13秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <inttypes.h>

#define max_range 10000

int prime[max_range] = {0};
int min_sum[max_range] = {0};
int num_sum[max_range] = {0};


void is_prime1() {   //因数个数
    for (int i = 2; i < max_range; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            min_sum[i] = 1;
            num_sum[i] = 2;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if(i * prime[j] > max_range) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j]) {
                num_sum[i * prime[j]] = num_sum[i] * num_sum[prime[j]];
                min_sum[i * prime[j]] = min_sum[prime[j]];
            } else {
                num_sum[i * prime[j]] = num_sum[i] / (min_sum[prime[j]] + 1) * (min_sum[prime[j]] + 2);
                min_sum[i * prime[j]] = min_sum[prime[j]] + 1;
                break;
            }
        }
    }
}

void huadong() {            //滑动窗口法
    int sum = 1;
    int zero = 0;
    int maxn = 0;
    char s[max_range];
    for(int i = 0; i < 100; i++) {
        if(s[i] != '0') {
            sum *= s[i] - '0';
        } else {
            zero ++;
        }
        if(i > 12) {
            if(s[i - 13] != '0') {
                sum /= s[i] - '0';
            } else {
                zero--;
            }
        }
        if(zero == 0 && maxn < sum) {
            maxn = sum;
        }
    }
}

int gcd(int a, int b) {   //最大公约数
    if (b == 0) return a;
    return (b, a % b);
}

int binaru_search(int x, int n) {    //二分查找
    int head = 0, tail = n, mid = (head + tail) >> 1;
    while (head <= tail) {
        if(mid == x) return 1;
        if(mid < x) head = mid + 1;
        if(mid > x) tail = mid - 1;
        mid = (head + tail) >> 1;
    }
    return 0;
}


void kangtuo {
    int n = 9; //9个数的全排列
    int maxn = 9999; //状态数
    int mul = 2; // 阶乘
    for (int i = 0; i < n; i++) {
        int j = i + 1, t;
        while (n >= maxn && j < n) {
            k = a[i], a[i] = a[j], a[j] = t;
            maxn -= mul;
            ++j;
        }
        mul /= (n - i);
    }
}



int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        is_prime1();
        printf("%d %d %d\n", prime[n], min_sum[n], num_sum[n]);
    }
    return 0;
}
