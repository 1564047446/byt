/*************************************************************************
	> File Name: test22.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月02日 星期六 15时53分47秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdarg.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>
using namespace std;


int print(const char *format, ...) {
    va_list arg;
    va_start(arg, format);
    int i = 0, ret = 0;
    while(format[i]) {
        if(format[i] == '%') {
            ++i;
            switch (format[i]) {
                case '%': putchar('%'), ++ret; break;
                case 'd': {
                    int temp = va_arg(arg, int);
                    unsigned int num;
                    if(temp < 0) {
                        num = -temp;
                        putchar('-'), ++ret;
                    } else {
                        num = temp;
                    }
                    if(num == 0) {putchar('0'); ++ret; break;}
                    int digit = pow(10, floor(log10(num)));
                    while (digit) {
                        putchar(num / digit + '0'), ++ret;
                        num %= digit;
                        digit /= 10;
                    }
                    break;
                }
                case 'x': {
                    int temp = va_arg(arg, int);
                    int num;
                    num = temp;
                    if(temp < 0) {
                       unsigned char *p = (unsigned char *)&temp;
                        for(int i = 3; i >= 0; i--) {
                            unsigned char c = *(p + i);
                            if(c / 16 >= 10) {
                                putchar(c / 16 - 10 + 'a'), ++ret;
                            } else {putchar(c / 16 + '0'), ++ret;}
                            if(c % 16 >= 10) {
                                putchar(c % 16 - 10 + 'a'), ++ret;
                            } else {putchar(c % 16 + '0'), ++ret;}
                            
                        }
                        break;
                    } else {
                        num = temp;
                    }
                    if(num == 0) {putchar('0'); ++ret; break;}
                    int digit = pow(16, floor(log10(num)));
                    while (digit) {
                        if(num / digit >= 10)
                        putchar(num / digit + 'a' - 10), ++ret;
                        else putchar(num / digit + '0'), ++ret;
                        num %= digit;
                        digit /= 16;
                    }
                    break;
                }
            }
        } else {
            putchar(format[i]), ++ret;
        }
        i++;    
    }
}



/*int strcmp_my(const char *string1, const char *string2) {
    int sum = 0;
    for(int i = 0; string1[i] != '\0' || string2[i] != '\0'; i++) {
        sum += (int)(string1[i]) - (int)(string2[i]);
    }
    if(sum > 0) return 1;
    else if(sum == 0) return 0;
    else return -1;
}
*/

/*int strncmp_my(const char string1[], const char string2[], uint64_t n) {
    uint64_t i = 0;
    while (string1[i] && string2[i] && i < n && string1[i] == string2[i]) i++;
    if(i == n) return 0;
    return string1[i] - string2[i];
}

uint64_t strlen_my(const char string[]) {
    return 0;
}

*/

int main() {
    int a;

    while(~scanf("%d", &a)) {
        print("%d ", a);
        print("%x\n", a);
        printf("%d %x\n", a, a);
    }
    return 0;

}
