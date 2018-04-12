#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int cnt = 0;
    for (int i = 2; i <= 100000; i++) {
        ++cnt;
        if (is_prime(i)) {
            printf("%d\n", i);
        }
    }
}