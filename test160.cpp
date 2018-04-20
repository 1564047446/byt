/*************************************************************************
	> File Name: test160.cpp
	> Author:  muhuilin 
	> Mail: 
	> Created Time: 2018年04月19日 星期四 16时24分20秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int is_para(int x) {
	int n = 0;
	int temp = x;
	while (x) {
		n = n * 10 + x % 10;
		x /= 10;
	}
	return n == temp;
}

int is_prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) return 0;
	}
	return 1;
}

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	for (int i = 2; i <= 100; i++) {
		if (i < a) continue;
		if (i > b) {
			return 0;
		}
		if (is_para(i) && is_prime(i)) {
			printf("%d\n", i);
		}
	}
	for (int d1 = 1; d1 < 10; d1++) {
		for (int d2 = 0; d2 < 10; d2++) {
			int f = 100 * d1 + 10 * d2 + d1;
			if (f < a) continue;
			if (f > b) break;
			if (is_prime(f)) {
				printf("%d\n", f);
			}
		}
	}
	for (int d1 = 1; d1 < 10; d1 += 2) {
		for (int d2 = 0; d2 < 10; d2 += 2) {
			int f = 1000 * d1 + 100 * d2 + 10 * d2 + d1;
			if (f < a) continue;
			if (f > b) break;
			if (is_prime(f)) {
				printf("%d\n", f);
			}
		}
	}
	for (int d1 = 1; d1 < 10; d1 += 2) {
		for (int d2 = 0; d2 < 10; d2++) {
			for (int d3 = 0; d3 < 10; d3++) {
				int f = 10000 * d1 + 1000 * d2 + 100 * d3 + 10 * d2 + 1 * d1;
				if (f < a) continue;
				if (f > b) break;
				if (is_prime(f)) {
					printf("%d\n", f);
				}
			}
		}
	}
	for (int d1 = 1; d1 < 10; d1 += 2) {
		for (int d2 = 0; d2 < 10; d2++) {
			for (int d3 = 0; d3 < 10; d3++) {
				int f = 100000 * d1 + 10000 * d2 + 1000 * d3 + 100 * d3 + 10 * d2 + d1;
				if (f < a) continue;
				if (f > b) break;
				if (is_prime(f)) {
					printf("%d\n", f);
				}
			}
		}
	}
	for (int d1 = 1; d1 < 10; d1 += 2) {
		for (int d2 = 0; d2 < 10; d2++) {
			for (int d3 = 0; d3 < 10; d3++) {
				for (int d4 = 0; d4 < 10; d4++) {
					int f = 1000000 * d1 + 100000 * d2 + 10000 * d3 + 1000 * d4 + 100 * d3 + 10 * d2 + d1;
					//printf("%d\n", f);
					if (f < a) continue;
					if (f > b) break;
					if (is_prime(f)) {
						printf("%d\n", f);
					}
				}
			}
		}
	}
	return 0;
}
