/*************************************************************************
	> File Name: test40.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月15日 星期五 20时23分48秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ({ \
     __typeof(a)temp1 = (a);\
     __typeof(b)temp2 = (b);\
     temp1 > temp2 ? temp1 : temp2;\
})
int k = 19;
#define Plog(frm, arg...) { \
     va_list = arg1;\
     va_start(arg1, frm);\
     \
     \
}




void haizei_test() {
    int a = 6;
    Plog("%d", MAX(2, 3));
    Plog("%d", 5 + MAX(2, 3));
    Plog("%d", MAX(2, MAX(3, 4)));
    Plog("%d", MAX(2, 3 > 4 ? 3 : 4));
    Plog("%d", MAX(a++, 6));
    Plog("a value = %d", a);
}

int main() {
    haizei_test();
    return 0;
}
