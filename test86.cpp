/*************************************************************************
	> File Name: test86.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月25日 星期四 14时25分37秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

typedef struct Heap {
    int id, n, size;
    int *data;
}Heap;



int get_num() {
    static int n = 1;
    n = (n * 11) % 1001;
    if (n == 1) {
        
    }
    return n;
    /*(*ad)++;
    
    if (n % 2 == 0) get_num((n + 3) % 101, ad);
    if (n % 2 != 0) get_num((n + 1) % 101, ad);*/

}


int main() {
    srand((int)time(0));
    /*for (int i = 0; i < 100; i++) {
        printf("%d\n", rand() % 101);
    }*/

    int num = rand() % 101;
    int ad = 0;
    for (int i = 0; i < 1000; i++) {
        printf("%d\n", get_num());
    }
}
