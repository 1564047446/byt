/*************************************************************************
	> File Name: test30.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月07日 星期四 14时24分52秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>


#define MAX(a, b) ({   \
    __typeof(a)temp1 = a;\
    __typeof(b)temp2 = b;  \
    (temp1 > temp2) ? temp1 : temp2;  \
})



int print(const char *format, ...) {
    va_list arg;
    va_start(arg, format);
    int i = 0, ret = 0;
    while(format[i]) {
        if (format[i] == '%') {
            ++i;
            switch (format[i]) {
                case '%': putchar('%'), ++ret; break;
                case 'd': {
                    int temp = va_arg(arg, int);
                    //printf("%d\n", temp);
                    unsigned int num = 0;
                    if (temp < 0) {
                        putchar('-'), ++ret;
                        num = -temp;
                    } else num = temp;
                    //printf("%d\n", num);
                    if(temp == 0) {
                        putchar('0'), ++ret;
                        break;
                    }
                    int digit = pow(10, floor(log10(num)));
                    //printf("%d\n", temp);
                    while (digit) {
                        putchar(num / digit + '0'), ++ret;
                        num %= digit;
                        digit /= 10;
                    }
                    break;
                }
            }
        } else {
            putchar(format[i]), ++ret;
        }
        ++i;
    }
}


int main() {
    int a, b;
    while(scanf("%d", &a)) {
        //printf("%d\n", MAX(a, b));
        print("%d", a);
    }
}
