#include <stdio.h>
#include <inttypes.h>

// Input Your Code

#define TEST(a, b) \
    void test##a##_##b();   \
    int p##a##_##b = isPrime(1);   \
    void test##a##_##b()   \


#define EXPECT_EQ(a, b) { \
    __typeof(a)temp1 = (a); \
    __typeof(b)temp2 = (b); \
    temp1 == temp2 ? 1 : 0; \
} \

int isPrime(int x);

TEST(isPrime, bound) {
    EXPECT_EQ(isPrime(0), 0);
    EXPECT_EQ(isPrime(1), 0);
    EXPECT_EQ(isPrime(INT32_MIN), 0);
}

TEST(isPrime, okTest) {
    #ifndef MAX_N
        #define MAX_N 100
    #endif
    int prime[MAX_N + 5] = {1, 1};
    for (int i = 2; i * i <= MAX_N; i++) {
        if (!prime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                prime[j] = 1;
            }
        }
    }
    for (int i = 2; i <= MAX_N; i++) {
        EXPECT_EQ(isPrime(i), prime[i] == 0);
    }
}

TEST(isPrime, failedTest) {
    #ifndef MAX_N
        #define MAX_N 100
    #endif
    int prime[MAX_N + 5] = {1, 1};
    for (int i = 2; i * i <= MAX_N; i++) {
        if (!prime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                prime[j] = 1;
            }
        }
    }
    for (int i = 2; i <= MAX_N; i++) {
        EXPECT_EQ(isPrime(i), prime[i] == 1);
    }
}

int main() {
    return 0;
}

int isPrime(int x) {
    if (x <= 1) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

