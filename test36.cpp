/*************************************************************************
	> File Name: test36.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月11日 星期一 11时11分58秒
 ************************************************************************/

#include <stdio.h>

typedef struct Node {
    int ok;
    int fail;
} Node, *PNode;

/**sure {
    int ok;,
    int fail;
}sure;*/

void is_value(sure *__ti, int a, int b) {
    a == b ? __ti->ok++ : __ti->fail++;
}

int main() {
    int a, b;
    *PNode ti = {0, 0};
    while (~scanf("%d%d", &a, &b)) {
        is_value(&ti, a, b);
        printf("ok = %d,    fail = %d\n", ti.ok, ti.fail);
    }
}
