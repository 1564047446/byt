/*************************************************************************
	> File Name: test193.cpp
	> Author:  byt 
	> Mail: baotongyu1995@163.com
	> Created Time: 2018年06月05日 星期二 18时54分10秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

#define a a
int main() {
    cout << __DATA__ << endl;
    int m = 1, n = 2, *p = &m, *q = &n, *r;
    r = p, p = q, q = r;
    cout << m << " " << n << " " << *p << " " << *q << endl;
    printf("m : %p *p : %p *q : %p\n", &m, p, q);
    return 0;
}
