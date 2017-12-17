/*************************************************************************
	> File Name: print%x.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月03日 星期日 15时30分00秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <inttypes.h>
#include <math.h>


int print1(const char *format, ...) {
    va_list arg;
    va_start(arg, format);
    int i = 0, ret = 0;
    if(format[i] == '%') {
        ++i;
        if(format[i] == 'x') {
            int temp = va_arg(arg, int);
            unsigned char *p = (unsigned char *)&temp;
            int flag = 0;
            for(int i = 3; i >= 0; i--) {
                unsigned char num = *(p + i);
                if(num / 16 >= 10) {
                    if(flag || num / 16 +'a' - 10 != '0')
                    putchar(num / 16 + 'a' - 10), ++ret, flag = 1;
                } else {
                    if(flag || num / 16 +'0' != '0')   
                    putchar(num / 16 + '0'), ++ret, flag = 1;
                }
                if(num % 16 >= 10) {
                    if(flag || num % 16 +'a' - 10 != '0') 
                    putchar(num % 16 + 'a' - 10), ++ret, flag = 1;
                } else {
                    if(flag || num % 16 +'0' != '0') 
                    putchar(num % 16 + '0'), ++ret, flag = 1;
                }
            }
        }
    } else {
        putchar(format[i]), ++ret;
    }
    i++;
}

int print2(const char *format, ...) {
    va_list arg;
    va_start(arg, format);
    int i = 0, ret = 0;
    if(format[i] == '%') {
        i++;
        if(format[i] == 'x') {
            int temp = va_arg(arg, int);
            unsigned int num = 0, num2 = temp;
            int a = 0;
            while (num2) {
                num = (num << 4) | (num2 & 15);
                num2 >>= 4;
                ++ a;
            }
            //num *= (16, b - a);
            do {
                if((num & 15) >= 10) {
                    putchar((num & 15) + 'a' - 10), ++ret;
                    
                } else {
                    putchar((num & 15) + '0'), ++ret;
                }
                num >>= 4;
            } while(a-- > 1);
        }
    }
}



int main() {
    for(int i = -100; i < 10000; i++) {
        printf("%x ", i);
        //print1("%x", i);
        print2("%x", i);
        printf("\n");
    }
}
