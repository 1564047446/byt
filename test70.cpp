/*************************************************************************
	> File Name: test70.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月20日 星期六 17时22分08秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

union ip {
    int num;
    char p[4];
};

int main() {
    int num[4];
    while (~scanf("%d.%d.%d.%d", num + 3, num + 2, num + 1, num + 0)) {
        ip ip1;
        for (int i = 3; i >= 0; i--) {
            ip1.p[i] = num[i] & ((1 << 8) - 1);
            printf("%02X\n", num[i]);
            printf("%d\n", num[i]);
        }
        printf("%08X\n", ip1.num);
    }
}
