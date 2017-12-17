/*************************************************************************
	> File Name: test33.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月08日 星期五 20时47分04秒
 ************************************************************************/

#include <stdio.h>

typedef struct my_test {
    int ok = 0;
    int fail = 0;
    int b = 0;
    int num = 0;
}Node *New;

New my_test1;


#define TEST(a,b)        \
    void test##a##_##b();  \
    int p##a##_##b = kong(test##a##_##b, #a, #b); \
    void test##a##_##b()   \

#define EXPECT(a, b) ({   \
    __typeof(a)temp1 = (a);     \
    __typeof(b)temp2 = (b);     \
    temp1 == temp2 ? (++my_test1.ok, printf("\033[31m OK = %d    FAIL = %d\n\033[0m", my_test1.ok, fail)) : (++my_test1.fail, printf("\033[31m OK = %d     FAIL = %d\n\033[0m", my_test1.ok, my_test1.fail));\
})


int kong(void (*func)(), const char *s1, const char *s2) {
    printf("\033[32m s1 = %s    s2 = %s   total = %d\n\033[0m", s1, s2, ++my_test1.num);
    my_test1.b = 0;
    func();
    return 0;
}


TEST(A, B) {
    printf("output : A B\n");
    my_test1.b = 1;
    EXPECT(1, my_test1.b);
}

TEST(C, D) { 
    printf("output : C D\n");
    EXPECT(1, my_test1.b);
}

TEST(E, F) {
    printf("output : E F \n");
    EXPECT(1, my_test1.b);
}



int main() {
	//TESTAB();
	//TESTCD();
	testA_B();
 //printf("\033[40;36m World\n\033[0m");
	return 0;
}
