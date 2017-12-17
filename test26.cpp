/*************************************************************************
	> File Name: test26.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月04日 星期一 18时44分36秒
 ************************************************************************/

#include <stdio.h>


struct person {
    char name[20];
    int age;
    char gender;
    float height;
};

struct nodea {
    char a;
    char b;
    int c;
};

struct nodeb {
    char a;
    int c;
    char b;
};


union node {
    
    struct id1 {
        unsigned char a;
        unsigned char b;
        unsigned char c;
        unsigned char d;
    }id;
    unsigned int num;
};

int main() {
    printf("%d %d\n", sizeof(struct nodea), sizeof(struct nodeb));
    node k;
    //k.b = 2.0;
    int a1, b1, c1, d1;
    scanf("%d.%d.%d.%d", &a1, &b1, &c1, &d1);
    k.id.a = a1;
    k.id.b = b1;
    k.id.c = c1;
    k.id.d = d1;
    printf("%d\n", k.num);

}
