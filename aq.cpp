/*************************************************************************
	> File Name: aq.cpp
	> Author:  muhuilin 
	> Mail: 
	> Created Time: 2018年04月14日 星期六 17时08分35秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main() {
    int sum = 0;
    for (int i = 0; i <= 20000; i++) {
        sum += i;
    }
    cout << sum << endl;
}
