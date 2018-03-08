/*************************************************************************
	> File Name: test45.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月02日 星期二 15时46分28秒
 ************************************************************************/

#include <stdio.h>

#define max(a, b)({ \
    __typeof(a)temp1 = a; \
    __typeof(b)temp2 = b; \
    temp1 > temp2 ? temp1 : temp2; \
})



int main() {
    int a, b;
    while (~scanf("%d%d", &a, &b)) {
        printf("max = %d\n", max(a, b));
    }
}
